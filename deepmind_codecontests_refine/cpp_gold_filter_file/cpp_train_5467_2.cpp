#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 8;
const int logN = 20, BL = 400;
const double EPS = 3e-16;
long long n, dimension[2], low[2], high[2], cur[2], ans = 0;
string s;
bool ground() { return dimension[0] > 0 && dimension[1] > 0; }
bool expand(long long m, bool hit) {
  if (m != 0 && m % n == 0 && cur[0] == 0 && cur[1] == 0) {
    puts("-1");
    exit(0);
  }
  char type = s[m % n];
  if (type == 'L') hit ? cur[0] = high[0] + 1 : cur[0]++;
  if (type == 'R') hit ? cur[0] = low[0] - 1 : cur[0]--;
  if (type == 'U') hit ? cur[1] = high[1] + 1 : cur[1]++;
  if (type == 'D') hit ? cur[1] = low[1] - 1 : cur[1]--;
  bool expanded = false;
  for (long long i = 0; i < 2; i++) {
    if (cur[i] < low[i] || cur[i] > high[i]) {
      ans = (ans + (m + 1) % MOD * dimension[i ^ 1]) % MOD;
      dimension[i]--;
      expanded = true;
    }
    if (cur[i] < low[i]) low[i] = cur[i];
    if (cur[i] > high[i]) high[i] = cur[i];
  }
  return expanded;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> dimension[1] >> dimension[0] >> s;
  for (long long i = 0; ground() && i < n; i++) {
    expand(i, false);
  }
  vector<long long> expanding_indexes;
  for (long long i = n; ground() && i < n * 2; i++) {
    if (expand(i, false)) {
      expanding_indexes.push_back(i % n);
    }
  }
  for (long long i = 2; ground(); i++) {
    for (long long m : expanding_indexes) {
      if (ground()) {
        expand(i * n + m, true);
      }
    }
  }
  cout << ans;
  return 0;
}
