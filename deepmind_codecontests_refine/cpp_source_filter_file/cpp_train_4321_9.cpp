#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e4 + 4, nlg = 63;
int mods, N;
struct Mat {
  long long a[2][2];
  inline Mat() { memset(a, 0, sizeof(a)); }
  inline void setorg() { a[0][0] = a[1][1] = 1; }
  inline void print() {
    for (long long i = 0; i < 2; ++i) {
      for (long long j = 0; j < 2; ++j) {
        cout << a[i][j] << ' ';
      }
      cout << endl;
    }
  }
} pro[maxn][nlg];
inline Mat operator*(const Mat& a, const Mat& b) {
  Mat res;
  for (long long i = 0; i < 2; ++i)
    for (long long j = 0; j < 2; ++j)
      for (long long k = 0; k < 2; ++k)
        (res.a[i][j] += a.a[i][k] * b.a[k][j]) %= mods;
  return res;
}
long long S[maxn];
inline Mat setval(long long si1, long long si) {
  Mat x;
  x.a[0][0] = 0;
  x.a[0][1] = si1;
  x.a[1][0] = 1;
  x.a[1][1] = si;
  return x;
}
inline long long goright(long long x) { return (x % N + N) % N; }
inline Mat mreg(long long l, long long r) {
  Mat res;
  res.setorg();
  for (long long k = nlg - 1; k >= 0; --k)
    if (l + (1ll << k) - 1 <= r)
      res = res * pro[goright(l)][k], l += (1ll << k);
  return res;
}
pair<long long, long long> prs[maxn];
signed main() {
  long long M, K;
  cin >> K >> mods;
  cin >> N;
  if (K == 0) {
    cout << 0 << endl;
    return 0;
  } else if (K == 1) {
    cout << 1 % mods << endl;
    return 0;
  }
  for (long long i = 0; i < N; ++i) cin >> S[i];
  for (long long i = 0; i < N; ++i)
    pro[i][0] = setval(S[goright(i - 2)], S[goright(i - 1)]);
  for (long long k = 1; k < nlg; ++k)
    for (long long i = 0; i < N; ++i)
      pro[i][k] = pro[i][k - 1] * pro[goright(i + (1 << (k - 1)))][k - 1];
  Mat r;
  r.a[0][0] = 0, r.a[0][1] = 1;
  long long pos = 1;
  cin >> M;
  for (long long i = 0; i < M; ++i) cin >> prs[i].first >> prs[i].second;
  sort(prs, prs + M);
  for (long long i = 0; i < M; ++i) {
    auto [p, v] = prs[i];
    if (p >= K) break;
    r = r * mreg(pos + 1, p);
    pos = p + 1;
    Mat s;
    if (i > 0 && prs[i - 1].first == p - 1)
      s = setval(prs[i - 1].second, v);
    else
      s = setval(S[goright(p - 1)], v);
    if (((i < M - 1 && prs[i + 1].first > p + 1) || i == M - 1) && p + 1 < K) {
      s = s * setval(prs[i].second, S[goright(p + 1)]);
      ++pos;
    }
    r = r * s;
  }
  r = r * mreg(pos + 1, K);
  cout << r.a[0][1] << endl;
  return 0;
}
