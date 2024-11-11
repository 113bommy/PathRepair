#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long power(long long a, long long n, long long m) {
  if (n == 0) return 1;
  long long p = power(a, n >> 1, m);
  p = (p * p) % m;
  if (n & 1) p = (p * a) % m;
  return p;
}
pair<int, int> solveFor(vector<int> &A, int m) {
  int n = A.size();
  if (n == 0) return pair<int, int>(0, 1);
  if (n == 1) return pair<int, int>(A[0], 1);
  int x = (A[1] - A[0] + m) % m;
  int nt = 0;
  for (int i = 0; i < n; i++) {
    int nxt = (A[i] + x) % m;
    int p = lower_bound(A.begin(), A.end(), nxt) - A.begin();
    if (p < n and A[p] == nxt) nt++;
  }
  int k = n - nt;
  if (k == 0) return pair<int, int>(-1, -1);
  int d = (x * power(k, m - 2, m)) % m;
  int a = -1;
  for (int i = 0; i < n; i++) {
    int nxt = (A[i] - d + m) % m;
    int p = lower_bound(A.begin(), A.end(), nxt) - A.begin();
    if (p < n and A[p] == nxt) continue;
    if (a == -1)
      a = A[i];
    else
      return pair<int, int>(-1, -1);
  }
  if (a == -1) a = A[0];
  return make_pair(a, d);
}
vector<int> A, B;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());
  if (2 * n < m) {
    auto ret = solveFor(A, m);
    if (ret.first == -1)
      cout << "-1\n";
    else
      cout << ret.first << " " << ret.second << "\n";
  } else {
    for (int i = 0; i < m; i++) {
      int p = lower_bound(A.begin(), A.end(), i) - A.begin();
      if (p < n and A[p] == i) continue;
      B.push_back(i);
    }
    auto ret = solveFor(B, m);
    if (ret.first == -1)
      cout << "-1\n";
    else {
      ret.first = (ret.first - (n * ret.second) % m + m) % m;
      cout << ret.first << " " << ret.second << "\n";
    }
  }
  return 0;
}
