#include <bits/stdc++.h>
using namespace std;
template <typename I>
void _DO(I &&x) {
  cerr << x << endl;
}
template <typename I, typename... T>
void _DO(I &&x, T &&...tail) {
  cerr << x << ", ";
  _DO(tail...);
}
template <typename A, typename B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &c) {
  s << "[ ";
  for (auto it : c) s << it << " ";
  s << "]";
  return s;
}
int N, a, b, c, d, start, len;
const int maxn = 3e5 + 2;
long long T[maxn], pfx_nt[maxn], pfx_t[maxn];
bool A[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> N >> a >> b >> c >> d >> start >> len;
  T[0] = 0;
  for (int i = 1; i <= N; i++) {
    int t, ac;
    cin >> t >> ac;
    T[i] = t;
    A[i] = (bool)ac;
  }
  pfx_nt[0] = pfx_t[0] = start;
  for (int i = 1; i <= N; i++) {
    pfx_nt[i] = pfx_nt[i - 1];
    pfx_t[i] = pfx_t[i - 1];
    if (A[i])
      pfx_nt[i] += a, pfx_t[i] += c;
    else
      pfx_nt[i] -= b, pfx_t[i] -= d;
  }
  set<long long> S;
  int cnt = 1;
  for (int i = 0; i <= N; i++) {
    if (pfx_nt[i] < 0) {
      cout << -1 << '\n';
      return 0;
    }
    if (i) S.erase(S.find(pfx_t[i]));
    while (cnt <= N && T[cnt] - (T[i] + 1) < len) S.insert(pfx_t[cnt++]);
    if (S.size() == 0) {
      cout << T[i] + 1 << '\n';
      return 0;
    }
    long long val = *S.begin() - pfx_t[i];
    val += pfx_nt[i];
    if (val >= 0) {
      cout << T[i] + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
