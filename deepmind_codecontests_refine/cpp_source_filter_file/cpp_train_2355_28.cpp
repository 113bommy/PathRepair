#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e4 + 1;
long long cnt[mxN];
const int vrti = 1e5 + 4;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  if (n % 4 == 0) {
    cout << "YES\n";
    for (int i = 0; i + 4 < n; i++) {
      cout << i + vrti << " ";
    }
    if (x == 3 || x == 4 || x == 7) {
      cout << "1 8 9 " << x;
    } else {
      cout << " 3 4 7 " << x;
    }
    return 0;
  }
  if (n % 4 == 1) {
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++) {
      cout << i + vrti << " ";
    }
    cout << x << " ";
    return 0;
  }
  if (n % 4 == 3) {
    cout << "YES\n";
    for (int i = 0; i + 3 < n; i++) {
      cout << i + vrti << " ";
    }
    if (x == 0) {
      cout << "1 8 9";
    } else {
      if (x != 1)
        cout << "0 1 " << (1 ^ x);
      else
        cout << "0 2 " << (2 ^ x);
    }
    return 0;
  }
  if (x != 0) {
    cout << "YES\n";
    for (int i = 0; i + 2 < n; i++) {
      cout << i + vrti << " ";
    }
    cout << "0 " << x;
    return 0;
  }
  if (n == 2) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i + 6 < n; i++) {
    cout << i + vrti << " ";
    cout << "0 1 2 4 8 15";
  }
}
