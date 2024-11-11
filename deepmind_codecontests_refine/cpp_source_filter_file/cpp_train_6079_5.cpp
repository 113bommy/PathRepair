#include <bits/stdc++.h>
using namespace std;
int b[100006];
int main() {
  int sum = 0, x, y;
  b[-1] = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == s[i + 1]) sum++;
    b[i] = sum;
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    cout << b[y - 2] - b[x - 2];
  }
}
