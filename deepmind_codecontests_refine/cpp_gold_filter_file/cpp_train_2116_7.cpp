#include <bits/stdc++.h>
using namespace std;
int cnt[104][26];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    for (int j = 0; j < m; j++) cnt[j][a[j] - 'A'] = 1;
  }
  long long res = 1ll;
  for (int i = 0; i < m; i++) {
    int ct = 0;
    for (int j = 0; j < 26; j++) ct += cnt[i][j];
    res = (res * (long long)ct) % 1000000007;
  }
  cout << res << endl;
  return 0;
}
