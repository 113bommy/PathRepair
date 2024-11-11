#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
int n;
int m;
pair<int, int> r[100000];
bool myless(pair<int, int> a, pair<int, int> b) {
  swap(a.first, a.second);
  swap(b.first, b.second);
  return a < b;
}
long long t[800000];
const long long mod = 1000000007;
int K = 1;
void upd(int v, long long x) {
  v += K;
  t[v] = (t[v] + x) % mod;
  while (v != 1) {
    v /= 2;
    t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
  }
}
long long rsq(int v, int l, int r, int L, int R) {
  if (L <= l && r <= R) return t[v];
  if (l > R || r < L) return 0;
  return (rsq(v * 2, l, (l + r) / 2, L, R) +
          rsq(v * 2 + 1, (l + r) / 2 + 1, r, L, R)) %
         mod;
}
int main() {
  cin >> n >> m;
  set<int> x;
  x.insert(0);
  x.insert(n);
  for (int i = 0; i < (m); i++) {
    cin >> r[i].first >> r[i].second;
    x.insert(r[i].first);
    x.insert(r[i].second);
  }
  map<int, int> y;
  int tmp = 0;
  for (set<int>::iterator i = x.begin(); i != x.end(); i++) {
    y[*i] = tmp++;
  }
  n = y[n];
  for (int i = 0; i < (m); i++) {
    r[i].first = y[r[i].first];
    r[i].second = y[r[i].second];
  }
  sort(r, r + m, myless);
  while (K < n) K <<= 1;
  upd(0, 1);
  for (int i = 0; i < (m); i++) {
    upd(r[i].second, rsq(1, 0, K - 1, r[i].first, r[i].second - 1));
  }
  cout << t[K + n] << endl;
  return 0;
}
