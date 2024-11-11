#include <bits/stdc++.h>
using namespace std;
long long int sz;
long long int n, m;
vector<long long int> v;
vector<long long int> st;
map<long long int, long long int> M;
long long int build(int p, int L, int R, int flag) {
  if (L == R) {
    st[p] = v[L];
    M[L] = p;
    return st[p];
  }
  long long int x = build(2 * p, L, (L + R) / 2, flag ^ 1);
  long long int y = build(2 * p + 1, (L + R) / 2 + 1, R, flag ^ 1);
  if (flag) {
    st[p] = x | y;
  } else {
    st[p] = x ^ y;
  }
  return st[p];
}
void change(int p, int flag) {
  if (flag) {
    st[p] = st[2 * p] | st[2 * p + 1];
  } else {
    st[p] = st[2 * p] ^ st[2 * p + 1];
  }
  if (p != 1) change(p / 2, flag ^ 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> sz >> m;
  n = (long long int)(1LL << sz);
  v.resize(n + 1);
  st.resize(4 * (n + 1));
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int fl = (sz) ? 0 : 1;
  build(1, 0, n - 1, fl);
  for (int i = 0; i < m; i++) {
    long long int p, b;
    cin >> p >> b;
    p--;
    st[M[p]] = b;
    change(M[p] / 2, 1);
    cout << st[1] << "\n";
  }
  return 0;
}
