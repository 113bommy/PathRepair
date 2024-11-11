#include <bits/stdc++.h>
using namespace std;
long long b[1100000];
vector<long long> g[600000];
long long c;
void check(long long l, long long r) {
  long long x = g[l].size();
  long long y = g[r].size();
  long long i;
  for (i = 0; i < min(x, y); i++) {
    if (g[l][i] != g[r][i]) break;
  }
  if (i == min(x, y)) {
    if (y >= x) {
      b[0]++;
      b[c + 1]--;
    }
  } else {
    if (g[l][i] > g[r][i]) {
      b[c - g[l][i] + 1]++;
      b[c - g[r][i] + 1]--;
    } else {
      b[0]++;
      b[c - g[l][i] + 1]++;
      b[c - g[r][i] + 1]--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i, j;
  cin >> n >> c;
  for (i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    for (j = 0; j < x; j++) {
      long long y;
      cin >> y;
      g[i].push_back(y);
    }
  }
  for (i = 1; i < n; i++) {
    check(i, i + 1);
  }
  for (i = 1; i <= c; i++) b[i] += b[i - 1];
  for (i = 0; i <= c; i++) {
    if (b[i] == n - 1) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
