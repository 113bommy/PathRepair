#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<char> v(n);
  for (auto& x : v) cin >> x;
  for (int i = 0; i < n - 5; i++) {
    for (int j = 1; j <= (n - 1 - i) / 4; j++) {
      if (v[i] == '*' && v[i + j] == '*' && v[i + 2 * j] == '*' &&
          v[i + 3 * j] == '*' && v[i + 4 * j] == '*') {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
