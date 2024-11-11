#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
long long int n, a[100005], cnt = 0, m;
string second;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  getline(cin, second);
  long long int x = 0;
  while (x < n) {
    getline(cin, second);
    cnt = 0;
    for (long long int i = 0; i < second.size(); i++)
      if (second[i] == 'a' || second[i] == 'e' || second[i] == 'i' ||
          second[i] == 'u' || second[i] == 'o' || second[i] == 'y') {
        cnt++;
      }
    if (cnt != a[x]) {
      x++;
      continue;
    } else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
}
