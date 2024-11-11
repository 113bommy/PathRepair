#include <bits/stdc++.h>
using namespace std;
void kehsihba() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  kehsihba();
  long long n, m;
  cin >> n >> m;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long add = 0;
  for (int i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      arr[b - 1] = c - add;
    } else {
      cin >> b;
      if (a == 2) {
        add += b;
      } else {
        cout << arr[b - 1] + add << '\n';
      }
    }
  }
  return 0;
}
