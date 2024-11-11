#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  while (m--) {
    int a, b;
    char c, d;
    cin >> a >> b >> c >> d;
    for (int i = a - 1; i <= b - 1; i++)
      if (s[i] == c) s[i] = d;
  }
  cout << s;
}
