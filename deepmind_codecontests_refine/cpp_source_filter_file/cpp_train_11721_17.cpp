#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int n;
  vector<int> xs;
  BIT(int n) : n(n) { xs.resize(n + 1); }
  void add(int i, int v) {
    for (int x = i + 1; x <= n; x += x & -x) xs[x] += v;
  }
  int sum(int i) {
    int s = 0;
    for (int x = i + 1; x > 0; x -= x & -x) s += xs[x];
    return s;
  }
  int sum(int a, int b) { return sum(b) - sum(a - 1); }
};
int N;
int A[100000];
int C[100000];
queue<int> Q[100001];
queue<int> K[100000];
BIT bit(100000);
int next(int x, int k) {
  int lo = x, hi = N;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (bit.sum(mid) > k)
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < (N); i++) {
    cin >> A[i];
    A[i]--;
    if (Q[A[i]].empty()) bit.add(i, 1);
    Q[A[i]].push(i);
  }
  for (int k = 0; k < (N); k++) K[0].push(k);
  for (int i = 0; i < (N); i++) {
    while (!K[i].empty()) {
      int k = K[i].front();
      K[i].pop();
      C[k]++;
      int t = next(i, k + 1);
      K[t].push(k);
    }
    bit.add(i, -1);
    assert(!Q[A[i]].empty() && Q[A[i]].front() == i);
    Q[A[i]].pop();
    if (!Q[A[i]].empty()) bit.add(Q[A[i]].front(), 1);
  }
  for (int i = 0; i < (N); i++) cout << C[i] << " ";
  cout << "\n";
  return 0;
}
