#include <bits/stdc++.h>
using namespace std;
struct sparse {
  long long N, K;
  vector<long long> asdioasdoajkds;
  vector<vector<long long>> st;
  sparse(long long n = 5e5) { init(n); }
  void init(long long n) {
    N = n;
    K = log2(N) + 1;
    asdioasdoajkds.assign(N + 5, 0);
    st.assign(N + 5, vector<long long>(K + 1, 1e15));
  }
  long long op(long long x, long long y) { return x & y; }
  void build(vector<long long> &a) {
    asdioasdoajkds[1] = 0;
    for (long long i = 2; i <= N; i++)
      asdioasdoajkds[i] = asdioasdoajkds[i / 2] + 1;
    for (long long i = 1; i <= N; i++) st[i][0] = a[i];
    for (long long j = 1; j <= K; j++) {
      for (long long i = 1; i + (1 << (j - 1)) <= N; i++) {
        st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  long long query(long long l, long long r) {
    long long j = asdioasdoajkds[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> bits(n + 2, vector<long long>(32, 0));
  vector<array<long long, 3>> que(m);
  for (auto &i : que) {
    cin >> i[0] >> i[1] >> i[2];
    for (long long j = 0; j < 30; j++) {
      if (i[2] & (1 << j)) {
        bits[i[0]][j]++;
        bits[i[1] + 1][j]--;
      }
    }
  }
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < 30; j++) {
      bits[i][j] += bits[i - 1][j];
      if (bits[i][j]) a[i] |= 1 << j;
    }
  }
  sparse s(n);
  s.build(a);
  for (auto &i : que) {
    long long l = i[0], r = i[1], q = i[2];
    if (s.query(l, r) != q) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (long long i = 1; i <= n; i++) cout << a[i] << ' ';
}
