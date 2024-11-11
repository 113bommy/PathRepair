#include <bits/stdc++.h>
using namespace std;
const int nm = 100005;
const int mod = 1000000007;
char s[nm], s2[nm];
int n, m;
int t[nm];
vector<int> x;
int f[nm], sum[nm], ss[nm];
void kmp() {
  t[0] = -1;
  t[1] = 0;
  int i, j = 0;
  for (i = 2; i <= m;) {
    if (s2[i - 1] == s2[j])
      t[i++] = ++j;
    else {
      if (j)
        j = t[j];
      else
        t[i++] = 0;
    }
  }
  for (i = 0, j = 0; i + m - 1 < n;) {
    if (s[i + j] == s2[j]) {
      if (j == m - 1) {
        x.push_back(i + 1);
        i += j - t[j];
        if (j) j = t[j];
      } else
        j++;
    } else {
      i += j - t[j];
      if (j) j = t[j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> s2;
  n = strlen(s);
  m = strlen(s2);
  kmp();
  if (x.size() == 0) {
    cout << "0\n";
    return 0;
  }
  f[0] = sum[0] = ss[0] = 1;
  int j = 0;
  for (int i = 1; i <= n; ++i) {
    while (j + 1 < x.size() && x[j + 1] + m - 1 <= i) ++j;
    if (x[j] + m - 1 <= i)
      f[i] = ss[x[j] - 1];
    else
      f[i] = 0;
    sum[i] = (sum[i - 1] + f[i]) % mod;
    ss[i] = (ss[i - 1] + sum[i]) % mod;
  }
  cout << (sum[n] + mod - 1) % mod << "\n";
}
