#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans = 0;
vector<int> a[30];
bool mark[(100)];
int main() {
  cin.tie();
  cout.tie();
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  long long maxa = 0;
  n = s.size();
  for (int i = 0; i < n; i++) a[s[i] - 'A'].push_back(i);
  for (int i = 0; i < 27; i++) {
    if (a[i].size() == 0) continue;
    int s = 0, x = a[i][s], y = (10e17 + 9);
    while (++s < a[i].size()) {
      if ((a[i][s] - x) % 2 == 1) {
        ans++;
        x = a[i][s];
      } else
        y = min(s, y);
    }
    maxa = max(maxa, ans);
    ans = 0;
    if (y != (10e17 + 9)) {
      s = y, x = a[i][s];
      while (++s < a[i].size()) {
        if ((a[i][s] - x) % 2 == 1) {
          ans++;
          x = a[i][s];
        } else
          y = min(s, y);
      }
    }
    maxa = max(ans, maxa);
    ans = 0;
  }
  cout << maxa + 1;
}
