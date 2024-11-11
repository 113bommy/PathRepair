#include <bits/stdc++.h>
using namespace std;
struct mone {
  int value = -1;
};
const int N = 2e5 + 5;
bool comp(int x, int y) { return x > y; }
bool is_square(long long int n) {
  if (pow((long long int)sqrt(n), 2) == n) return true;
  return false;
}
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int t1 = a, t2 = b;
  string s;
  cin >> s;
  s = '0' + s;
  for (int i = 1; i <= n; i++) {
    int c = 0;
    if (s[i] == '.') c++;
    while (i + 1 <= n and s[i + 1] != '*') i++, c++;
    if (a < b) {
      b -= (c + 1) / 2;
      a -= c / 2;
    } else {
      a -= (c + 1) / 2;
      b -= c / 2;
    }
    i++;
  }
  cout << t1 - max(0, a) + t2 - max(0, b) << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
