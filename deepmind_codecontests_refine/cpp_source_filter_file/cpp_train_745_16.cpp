#include <bits/stdc++.h>
using namespace std;
vector<long long> base;
void gen(long long v, int dep) {
  if (dep > 9) return;
  base.push_back(v);
  gen(v * 10 + 4, dep + 1);
  gen(v * 10 + 7, dep + 1);
}
void gen() { gen(0, 0); }
map<int, bool> isLucky;
vector<long long> frac;
int ov[20], cv[20];
int main() {
  gen();
  sort(base.begin(), base.end());
  isLucky.clear();
  for (int i = 0; i < (int)base.size(); i++) isLucky[(int)base[i]] = true;
  frac.clear();
  frac.push_back(1);
  for (int i = 1;; i++) {
    long long v = frac[i - 1] * i;
    if (v > 1E17) break;
    frac.push_back(v);
  }
  int n, k;
  cin >> n >> k;
  if (n <= (int)frac.size()) {
    if (frac[n] < k)
      cout << "-1" << endl;
    else {
      k--;
      for (int i = 1; i <= n; i++) {
        ov[i] = k / frac[n - i];
        k %= frac[n - i];
      }
      vector<int> l;
      for (int i = 1; i < (int)n + 1; i++) l.push_back(i);
      for (int i = 1; i < (int)n + 1; i++) {
        cv[i] = l[ov[i]];
        swap(l[ov[i]], l[l.size() - 1]);
        l.pop_back();
        sort(l.begin(), l.end());
      }
      int ans = 0;
      for (int i = 1; i < (int)n + 1; i++)
        if (isLucky[i] && isLucky[cv[i]]) ans++;
      cout << ans << endl;
    }
  } else {
    k--;
    int N = frac.size();
    for (int i = 1; i <= N; i++) {
      ov[i] = k / frac[N - i];
      k %= frac[N - i];
    }
    vector<int> l;
    for (int i = n; i > n - N; i--) l.push_back(i);
    sort(l.begin(), l.end());
    for (int i = 1; i < (int)N + 1; i++) {
      cv[i] = l[ov[i]];
      swap(l[ov[i]], l[l.size() - 1]);
      l.pop_back();
      sort(l.begin(), l.end());
    }
    int ans = 0;
    for (int i = 1; i < (int)N + 1; i++)
      if (isLucky[i + (n - N)] && isLucky[cv[i]]) ans++;
    for (int i = 0; i < (int)base.size(); i++) {
      int v = base[i];
      if (v <= n - N) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
