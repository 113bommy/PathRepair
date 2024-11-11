#include <bits/stdc++.h>
using namespace std;
vector<long long> X;
map<long long, pair<int, long long> > M;
pair<int, long long> go(long long x) {
  if (x <= 1) return {x, x};
  if (M.find(x) != M.end()) return M[x];
  int i = upper_bound(X.begin(), X.end(), x) - X.begin() - 1;
  int p1, p2;
  long long q1, q2;
  tie(p1, q1) = go(x - X[i]);
  tie(p2, q2) = go(X[i] - 1);
  return M[x] = max(make_pair(p1 + 1, q1 + X[i]), {p2, q2});
}
int main() {
  for (int i = 0; i <= 1e5 + 7; i++) X.push_back(1LL * i * i * i);
  long long x;
  cin >> x;
  int a;
  long long b;
  tie(a, b) = go(x);
  cout << a << " " << b << "\n";
}
