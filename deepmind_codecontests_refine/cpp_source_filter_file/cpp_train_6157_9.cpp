#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int X1, Y1, X2, Y2, n;
int a[N], b[N];
string s;
inline bool check(long long k) {
  return abs(X2 - X1 - k / n * a[n] - a[k % n]) +
             abs(Y2 - Y1 - k / n * b[n] - b[k % n]) <=
         k;
}
inline void readInput() {
  cin >> Y1 >> X1;
  cin >> Y2 >> X2;
  cin >> n >> s;
}
inline void solve() {
  for (int i = 0; i < n; i++) {
    a[i + 1] = a[i];
    b[i + 1] = b[i];
    if (s[i] == 'U') a[i + 1]++;
    if (s[i] == 'D') a[i + 1]--;
    if (s[i] == 'L') b[i + 1]--;
    if (s[i] == 'R') b[i + 1]++;
  }
  long long L = 0, R = 1e12 + 5;
  while (L + 1 < R) {
    long long mid = L + R >> 1;
    (check(mid) ? R : L) = mid;
  }
  cout << (R < 1e12 ? R : -1) << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  readInput(), solve();
  return 0;
}
