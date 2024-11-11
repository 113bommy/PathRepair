#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main() {
  int n, a, b;
  cin >> n;
  string s;
  bool yes = false;
  for (int i = 0; i < n; ++i) {
    cin >> s >> a >> b;
    if (a > 2400 && b > a) {
      yes = true;
      break;
    }
  }
  (yes) ? cout << "YES" : cout << "NO";
  return 0;
}
