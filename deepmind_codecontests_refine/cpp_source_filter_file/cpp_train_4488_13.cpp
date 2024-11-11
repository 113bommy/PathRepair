#include <bits/stdc++.h>
using namespace std;
int main() {
  int num[26] = {0};
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    num[s[i] - 'A']++;
  }
  int res = 1234567890;
  for (int i = 0; i < n; i++) {
    if (res > num[i]) res = num[i];
  }
  cout << res * m;
  return 0;
}
