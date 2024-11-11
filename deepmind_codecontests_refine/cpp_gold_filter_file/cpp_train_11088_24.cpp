#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e18;
int n;
string s;
int main() {
  cin >> n >> s;
  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) continue;
    ++len;
  }
  len = min(n, len + 2);
  cout << len;
  return 0;
}
