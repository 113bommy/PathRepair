#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  if (n == 2 || n == 3) {
    cout << s;
    return 0;
  }
  cout << s[0];
  if (n % 2 == 0) {
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0 && i < n) cout << "-";
      cout << s[i];
    }
  } else {
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0 && i < n - 2) cout << "-";
      cout << s[i];
    }
  }
  return 0;
}
