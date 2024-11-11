#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, k, cnt;
string s;
int main() {
  cin >> n >> k >> s;
  s = '1' + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '#')
      ++cnt;
    else if (cnt >= k)
      return cout << "NO", 0;
    else
      cnt = 0;
  }
  cout << "YES";
}
