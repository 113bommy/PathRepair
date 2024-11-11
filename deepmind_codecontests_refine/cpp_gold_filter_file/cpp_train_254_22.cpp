#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > DP;
long long N, k;
long long INF = 10000000000;
long long sstoi(string s) {
  bool ok = 0;
  if (s[0] == '-') {
    ok = 1;
    s.erase(0, 1);
  }
  long long ans = 0;
  long long i, j, k;
  j = 1;
  for (i = s.size() - 1; i >= 0; i--) {
    ans += (s[i] - '0') * j;
    j *= 10;
  }
  if (ok == 1) ans = -ans;
  return ans;
}
bool FL(long long n, long long x) {
  long long i, j, n1, n2, n3;
  n1 = (x - 1) / 2;
  if (DP[n][x] > n1)
    n1 = n1;
  else
    n1 = DP[n][x] - 1;
  for (i = x - 1; i >= 0; i--) {
    DP[n][i] = n1;
    n1--;
  }
  return 1;
}
bool FF(long long n, long long x, long long y) {
  if (x + 1 == y) {
    if (DP[n][y] <= DP[n][x]) return 0;
    return 1;
  }
  long long i, j, k, n1, n2, n3, m, L, R;
  m = (y - x - 1);
  if (DP[n][x] + m + 1 > DP[n][y]) return 0;
  L = -m / 2;
  R = m / 2;
  if (DP[n][x] >= L) {
    for (i = x + 1; i < y; i++) {
      DP[n][i] = DP[n][x] + (i - x);
    }
  } else if (DP[n][y] <= R) {
    for (i = y - 1; i > x; i--) {
      DP[n][i] = DP[n][y] - (y - i);
    }
  } else {
    n1 = L;
    for (i = x + 1; i < y; i++) {
      DP[n][i] = n1;
      n1++;
    }
  }
  return 1;
}
bool FR(long long n, long long y) {
  long long i, j, k, n1, n2, n3, m, L, R, LL;
  LL = DP[n].size();
  m = (LL - y - 1);
  L = -m / 2;
  R = m / 2;
  if (DP[n][y] >= L) L = DP[n][y] + 1;
  for (i = y + 1; i < LL; i++) {
    DP[n][i] = L;
    L++;
  }
  return 1;
}
bool calculate(long long n) {
  long long i, j, k, n1, n2, n3, L, R;
  j = 0;
  while (j < DP[n].size() && DP[n][j] == INF) j++;
  if (j == DP[n].size()) {
    n1 = DP[n].size();
    n2 = n1 / 2;
    n3 = -n1 / 2;
    if (n2 > N) {
      n3 = N - (n1 - 1);
    }
    for (i = 0; i < DP[n].size(); i++) {
      DP[n][i] = n3;
      n3++;
    }
    return 1;
  }
  L = j;
  if (FL(n, L) == 0) return 0;
  for (i = L + 1; i < DP[n].size(); i++) {
    if (DP[n][i] == INF) continue;
    R = i;
    if (FF(n, L, R) == 0) return 0;
    L = R;
  }
  if (DP[n][DP[n].size() - 1] == INF) {
    if (FR(n, L) == 0) return 0;
  }
  return 1;
}
bool solve() {
  long long i;
  for (i = 0; i < k; i++) {
    if (DP[i].size() == 0) continue;
    if (calculate(i) == 0) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  long long i, j, n1, n2, n3;
  cin >> N >> k;
  string s;
  DP.resize(k);
  bool ok = 0;
  for (i = 0; i < N; i++) {
    cin >> s;
    if (s == "?")
      DP[(i % k)].push_back(INF);
    else {
      j = sstoi(s);
      DP[(i % k)].push_back(j);
    }
  }
  if (solve() == 0)
    cout << "Incorrect sequence" << endl;
  else {
    for (i = 0; i < N; i++) {
      if (i != 0) cout << ' ';
      cout << DP[i % k][i / k];
    }
    cout << endl;
  }
  return 0;
}
