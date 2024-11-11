#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P) {
  in >> P.first >> P.second;
  return in;
}
template <class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P) {
  out << "(" << P.first << ", " << P.second << ")";
  return out;
}
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &x : arr) in >> x;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
  for (auto &x : arr) out << x << ' ';
  cout << "\n";
  return out;
}
template <class T>
istream &operator>>(istream &in, deque<T> &arr) {
  for (auto &x : arr) in >> x;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, const deque<T> &arr) {
  for (auto &x : arr) out << x << ' ';
  cout << "\n";
  return out;
}
long long n, m, q, k, v[100050];
pair<long long, long long> TT;
long long L, R;
long long dp[40][2][2][2][2];
long long solve(long long i, long long menorA, long long menorB,
                long long maiorA, long long maiorB) {
  if (i < 0) return 1;
  if (dp[i][menorA][menorB][maiorA][maiorB] != -1)
    return dp[i][menorA][menorB][maiorA][maiorB];
  long long ans = 0;
  for (long long a = 0; a < 2; a++) {
    for (long long b = 0; b < 2; b++) {
      if (a == 1 and b == 1) continue;
      if (!menorA and a == 1 and !(R & (1 << i))) continue;
      if (!menorB and b == 1 and !(R & (1 << i))) continue;
      if (!maiorA and a == 0 and (L & (1 << i))) continue;
      if (!maiorB and b == 0 and (L & (1 << i))) continue;
      long long mA = menorA, mB = menorB, kb = maiorB, ka = maiorA;
      if (a == 0 and (R & (1 << i))) mA = 1;
      if (b == 0 and (R & (1 << i))) mB = 1;
      if (a == 1 and !(L & (1 << i))) ka = 1;
      if (b == 1 and !(L & (1 << i))) kb = 1;
      ans += solve(i - 1, mA, mB, ka, kb);
    }
  }
  return dp[i][menorA][menorB][maiorA][maiorB] = ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    cin >> L >> R;
    memset(dp, -1, sizeof dp);
    cout << solve(20, 0, 0, 0, 0) << "\n";
  }
}
