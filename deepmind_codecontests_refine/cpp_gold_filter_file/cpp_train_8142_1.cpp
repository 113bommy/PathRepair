#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, mod = 963852751;
int n;
char a[maxn];
int sum[maxn];
long long hs[maxn];
long long m2[maxn];
int tot;
int main() {
  cin >> n >> a + 1;
  m2[0] = 1;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (a[i] == '0');
    if (a[i] == '0') {
      tot++;
      hs[tot] = (hs[tot - 1] * 2 + i % 2) % mod;
    }
    m2[i] = m2[i - 1] * 2 % mod;
  }
  int q, l1, l2, len;
  cin >> q;
  while (q--) {
    cin >> l1 >> l2 >> len;
    if (sum[l1 + len - 1] - sum[l1 - 1] != sum[l2 + len - 1] - sum[l2 - 1]) {
      cout << "No" << endl;
      continue;
    }
    len = sum[l1 + len - 1] - sum[l1 - 1];
    if (len == 0) {
      cout << "Yes" << endl;
      continue;
    }
    int flag = (l1 % 2 == l2 % 2);
    l1 = (a[l1] == '0' ? sum[l1] : sum[l1] + 1);
    l2 = (a[l2] == '0' ? sum[l2] : sum[l2] + 1);
    long long h1 = (hs[l1 + len - 1] - hs[l1 - 1] * m2[len] % mod + mod) % mod;
    long long h2 = (hs[l2 + len - 1] - hs[l2 - 1] * m2[len] % mod + mod) % mod;
    if (flag == 0) h1 = (m2[len] - 1 - h1 + mod) % mod;
    if (h1 == h2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
