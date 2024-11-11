#include <bits/stdc++.h>
using namespace std;
vector<int> divs[1000009];
bool p[1000009];
vector<int> primes;
void pre() {
  for (int i = 2; i <= (1000000); ++i) {
    if (!p[i]) {
      primes.push_back(i);
      for (int j = i; j <= 1000000; j += i) divs[j].push_back(i), p[j] = true;
    }
  }
}
int L(int x, int p) {
  int s = (int)(divs[p]).size();
  int tot = (1 << s) - 1;
  long long ans = 0;
  for (int i = 1; i <= (tot); ++i) {
    int cnt = 0;
    int var = 1;
    for (int j = 0; j < (s); ++j)
      if (i & (1 << j)) cnt++, var *= divs[p][j];
    if (cnt % 2)
      ans += x / var;
    else
      ans -= x / var;
  }
  return x - ans;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  pre();
  int q;
  cin >> q;
  for (int aa = 0; aa < (q); ++aa) {
    int x, p, k;
    cin >> x >> p >> k;
    if (p == 1)
      cout << k + x << '\n';
    else {
      k += L(x, p);
      int l = 1, r = 1e8;
      while (l < r) {
        int m = (l + r) >> 1;
        if (L(m, p) >= k)
          r = m;
        else
          l = m + 1;
      }
      cout << l << '\n';
    }
  }
  return 0;
}
