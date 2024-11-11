#include <bits/stdc++.h>
using namespace std;
long long int n, m;
long long int arr[300000];
string st, tt;
long long int cou[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int TESTS, q, a, s, b, r, k, c, p, w, d, x, i, j, y, z, xs, ys, t;
  TESTS = 1;
  while (TESTS--) {
    cin >> n;
    cin >> st;
    for (long long int i = 0; i <= 25; i++) cou[i] = 0;
    long long int maxi = 0;
    for (long long int i = 0; i <= n - 1; i++) {
      for (long long int j = st[i] - 'a' + 1; j <= 25; j++)
        cou[st[i] - 'a'] = max(cou[st[i] - 'a'], cou[j] + 1);
      arr[i] = cou[st[i] - 'a'];
      maxi = max(maxi, arr[i]);
    }
    cout << maxi << "\n";
    for (long long int i = 0; i <= n - 1; i++) cout << arr[i] << " ";
  }
  return 0;
}
