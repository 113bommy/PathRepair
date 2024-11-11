#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string nn[n], nm[m], ipn[n], ipm[m];
  int i;
  map<string, string> m1;
  for (i = 0; i < n; i++) {
    cin >> nn[i] >> ipn[i];
    m1[ipn[i]] = nn[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> nm[j] >> ipm[j];
    ipm[j].erase(ipm[j].begin() + (ipm[j].size() - 1));
  }
  for (i = 0; i < m; i++) {
    cout << nm[i] << " " << ipm[i] << "; #" << m1[ipm[i]];
    cout << endl;
  }
  return 0;
}
