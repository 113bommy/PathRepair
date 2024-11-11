#include <bits/stdc++.h>
using namespace std;
void solve(int caseo) {
  int n;
  cin >> n;
  string s;
  int cnt = 0;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int a1 = 0;
    int a2 = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == 'L') {
        a1--;
      }
      if (s[j] == 'R') {
        a1++;
      }
      if (s[j] == 'U') {
        a2++;
      }
      if (s[j] == 'D') {
        a2--;
      }
      if (!a1 && !a2) cnt++;
    }
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  for (int i = 0; i < t; i++) solve(i);
  return 0;
}
