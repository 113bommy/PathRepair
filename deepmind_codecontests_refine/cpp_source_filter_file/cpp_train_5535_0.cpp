#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dc[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int MAX = 500 + 7;
const int MOD = 1e9 + 7;
int main() {
  int n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; ++i) {
    int s, e, t;
    cin >> s >> e >> t;
    if (s == e) {
      cout << t << "\n";
      continue;
    }
    int k = t / (m - 1);
    int out = t;
    if (k % 2 == 0) {
      int cur = t - (k * (m - 1)) + 1;
      if (cur == s)
        out += (e - s > 0) ? (e - s) : (2 * m - s - e);
      else if (cur > s)
        out += ((2 * m - cur - s) + (s - e > 0) ? (s - e) : (s + e - 2));
      else if (cur < s)
        out += ((s - cur) + (e - s > 0) ? (e - s) : (2 * m - s - e));
    } else {
      int cur = m - (t - (k * (m - 1)));
      if (cur == s)
        out += (s - e > 0) ? (s - e) : (s + e - 2);
      else if (cur > s)
        out += ((cur - s) + (s - e > 0) ? (s - e) : (s + e - 2));
      else if (cur < s)
        out += ((cur + s - 2) + (e - s > 0) ? (e - s) : (2 * m - s - e));
    }
    cout << out << "\n";
  }
}
