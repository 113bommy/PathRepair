#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int solve(int l, int r) {
  set<char> ss;
  for (int i = l; i < r; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') return 0;
    ss.insert(s[i]);
  }
  return (int)ss.size();
}
int main() {
  scanf("%d", &n);
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      ans = max(ans, solve(i, j));
    }
  }
  printf("%d", ans);
  return 0;
}
