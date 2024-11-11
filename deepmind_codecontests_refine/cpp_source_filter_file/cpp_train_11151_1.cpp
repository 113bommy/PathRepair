#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int mod = 998244353;
  char a[200020], b[200020];
  int n, m;
  long long int cou = 0;
  cin >> n >> m;
  cin >> a;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (b[i] == '1') {
      cou++;
    }
  }
  long long int cur = 1;
  long long int ans = 0;
  int k = m - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == '1') {
      ans += (cur % mod * cou % mod) % mod;
    }
    if (b[k] == '1') {
      cou--;
    }
    k--;
    if (k < 0) {
      break;
    }
    cur = (cur % mod * 2) % mod;
  }
  cout << ans << endl;
}
