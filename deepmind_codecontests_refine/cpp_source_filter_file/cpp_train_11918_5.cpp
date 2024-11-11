#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
long long int D[mxn], H[mxn];
pair<long long int, long long int> st[4 * mxn];
int n, m, a, b;
long long int energy(pair<long long int, long long int> p) {
  int a1 = p.first, b1 = p.second;
  if (a1 == b1)
    return 2 * H[a1];
  else
    return 2 * (H[a1] + H[b1]) + D[b1 - 1] - D[a1 - 1];
}
pair<long long int, long long int> combine(
    pair<long long int, long long int> x,
    pair<long long int, long long int> y) {
  int l, r;
  int a1 = x.first, b1 = x.second;
  l = (2 * H[a1] + D[b1 - 1] - D[a1 - 1] > 2 * H[b1]) ? a1 : b1;
  int a2 = y.first, b2 = y.second;
  r = (2 * H[a2] >= D[b2 - 1] - D[a1 - 1] + 2 * H[b2]) ? a2 : b2;
  long long int X = energy(x), Y = energy(y), Z = energy({l, r});
  if (Z > X && Z > Y)
    return {l, r};
  else if (X > Y)
    return x;
  else
    return y;
}
void build(int p, int L, int R) {
  if (L == R) {
    st[p] = {L, L};
  } else {
    int mid = (L + R) / 2;
    build(2 * p, L, mid);
    build(2 * p + 1, mid + 1, R);
    st[p] = combine(st[2 * p], st[2 * p + 1]);
  }
}
pair<long long int, long long int> query(int p, int L, int R, int i, int j) {
  if (i > j)
    return {-1, -1};
  else if (i == L && R == j)
    return st[p];
  else {
    int mid = (L + R) / 2;
    pair<long long int, long long int> l = query(2 * p, L, mid, i, min(mid, j));
    pair<long long int, long long int> r =
        query(2 * p + 1, mid + 1, R, max(mid + 1, i), j);
    if (l.first == -1)
      return r;
    else if (r.first == -1)
      return l;
    else
      return combine(l, r);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  D[0] = 0;
  for (int i = 1; i <= n; ++i) cin >> D[i];
  for (int i = 1; i <= n - 1; ++i) D[n + i] = D[i];
  for (int i = 1; i <= 2 * n - 1; ++i) D[i] += D[i - 1];
  for (int i = 1; i <= n; ++i) cin >> H[i];
  for (int i = 1; i <= n - 1; ++i) H[n + i] = H[i];
  build(1, 1, 2 * n - 1);
  while (m--) {
    cin >> a >> b;
    pair<long long int, long long int> ans;
    if (a <= b)
      ans = query(1, 1, 2 * n - 1, b + 1, a + n - 1);
    else
      ans = query(1, 1, 2 * n - 1, b + 1, a - 1);
    cout << energy(ans) << "\n";
  }
}
