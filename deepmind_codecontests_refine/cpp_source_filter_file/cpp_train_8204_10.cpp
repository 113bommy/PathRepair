#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  string a, b;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int count = 0;
    a = s.substr(1, i);
    b = s.substr(i, s.size() - 1);
    for (char c = 'a'; c <= 'z'; c++) {
      if (a.find(c) != string::npos && b.find(c) != string::npos) count++;
    }
    ans = max(ans, count);
  }
  cout << ans;
  return 0;
}
