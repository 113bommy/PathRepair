#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> s >> a >> b;
    if (a >= 2400 && a != b) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
