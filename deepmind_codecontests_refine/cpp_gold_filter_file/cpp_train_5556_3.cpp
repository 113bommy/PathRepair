#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.length();
  int cnt = 0, maxm = 0, minm = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '+') {
      cnt++;
      maxm = max(maxm, cnt);
    } else {
      cnt--;
      minm = min(minm, cnt);
    }
  }
  cout << maxm - minm;
  return 0;
}
