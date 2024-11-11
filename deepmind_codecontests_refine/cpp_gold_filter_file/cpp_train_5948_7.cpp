#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s, rs = "";
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    if (i * (i - 1) / 2 >= n)
      break;
    else
      rs += s[i * (i - 1) / 2];
  }
  cout << rs;
}
