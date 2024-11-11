#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char c;
    string str;
    int n, i, j;
    set<int> s;
    cin >> n >> c >> str;
    if (str == string(n, c)) {
      cout << "0\n";
      continue;
    }
    for (i = n / 2; i < n; i++)
      if (str[i] == c) break;
    if (i == n)
      cout << "2\n" << n - 1 << ' ' << n << '\n';
    else
      cout << "1\n" << i + 1 << '\n';
  }
  return 0;
}
