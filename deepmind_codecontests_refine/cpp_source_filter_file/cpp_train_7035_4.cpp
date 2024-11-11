#include <bits/stdc++.h>
using namespace std;
const int MAXN = 212345;
string t, s;
int a[MAXN], mark[MAXN], n, m;
string get(int k) {
  memset(mark, 0, sizeof mark);
  for (int i = 0; i < k; ++i) mark[a[i]] = 1;
  string x = "";
  for (int i = 0; i < n; ++i)
    if (!mark[i]) x += t[i];
  return x;
}
bool check(int k) {
  string p = get(k);
  int last = 0;
  for (int i = 0; i < s.size(); ++i) {
    bool ok = false;
    for (int j = last; j < p.size(); ++j) {
      if (s[i] == p[j]) {
        last = j + 1;
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}
int bs() {
  int l = 1, r = n, best = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      best = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return best;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t >> s;
  n = t.size();
  m = s.size();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  cout << bs() << '\n';
  return 0;
}
