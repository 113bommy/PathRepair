#include <bits/stdc++.h>
using namespace std;
int main() {
  string st;
  stack<char> s;
  vector<char> v;
  long long n, i, ct = 1, ans = 0;
  cin >> n;
  cin >> st;
  for (i = 0; i < n; i++) {
    if (st[i] == 'B') ans += ct;
    ct *= 2;
  }
  cout << ans;
}
