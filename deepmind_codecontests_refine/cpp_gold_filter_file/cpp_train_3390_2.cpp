#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> n;
  cin >> m;
  string color;
  vector<string> pic;
  int a = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == 'C' || c == 'M' || c == 'Y') {
        color = "#Color";
        a = 1;
      }
    }
  }
  if (a == 0) {
    color = "#Black&White";
  }
  cout << color;
}
