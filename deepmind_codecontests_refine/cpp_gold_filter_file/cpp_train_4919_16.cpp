#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  if (2 * n <= s) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (i != n - 1)
        cout << "2 ";
      else
        cout << s - 2 * n + 2;
    }
    cout << "\n1\n";
  } else {
    cout << "NO\n";
  }
}
