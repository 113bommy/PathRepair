#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
long long D[100005];
long long dp[2][100005];
long long pre[100005];
long long ps[100005];
int que[100005];
struct Pt {
  long long d;
  long long cnt;
};
static inline long long cal(vector<Pt>& data, int i, int j) {
  return (ps[j] - ps[i - 1]) * (data[j].d - data[0].d) - (pre[j] - pre[i - 1]);
}
static inline int cmp(long long* from, int i, int j, int k) {
  long long ai = from[i] + pre[i];
  long long aj = from[j] + pre[j];
  long long ak = from[k] + pre[k];
  return (aj - ai) * (ps[k] - ps[j]) <= (ak - aj) * (ps[j] - ps[i]);
}
int main() {
  const int n = Rint(), m = Rint(), p = Rint();
  for (int i = 2; i <= n; ++i) D[i] = Rint();
  for (int i = 3; i <= n; ++i) D[i] += D[i - 1];
  vector<long long> vec;
  vector<long long> d0;
  for (int i = 0; i < m; ++i) {
    const int h = Rint();
    const int t = Rint();
    vec.push_back(t - D[h]);
  }
  vector<Pt> data;
  {
    sort((vec).begin(), (vec).end());
    const int n = ((int)(vec).size());
    for (int i = 0; i < n;) {
      int j = i + 1;
      while (j < n && vec[j] == vec[i]) ++j;
      Pt temp = {0};
      temp.d = vec[i];
      temp.cnt = j - i;
      data.push_back(temp);
      i = j;
    }
  }
  long long* from = dp[0];
  long long* to = dp[1];
  const int N = ((int)(data).size());
  {
    ps[0] = data[0].cnt;
    for (int i = 1; i < N; ++i) ps[i] = ps[i - 1] + data[i].cnt;
    for (int i = 0; i < N; ++i) pre[i] = data[i].cnt * (data[i].d - data[0].d);
    for (int i = 1; i < N; ++i) pre[i] += pre[i - 1];
    from[0] = 0;
    long long s = data[0].cnt;
    for (int i = 1; i < N; ++i) {
      from[i] = from[i - 1] + s * (data[i].d - data[i - 1].d);
      s += data[i].cnt;
    }
  }
  const int maxp = min(p, N);
  long long ans = from[N - 1];
  for (int id = 2; id <= maxp; ++id) {
    fill(to, to + N, 0);
    for (int i = 0; i < id - 1; ++i) to[i] = from[i];
    int p = 0, q = 0;
    que[q++] = id - 2;
    for (int i = id - 1; i < N; ++i) {
      while (p + 1 < q && from[que[p]] + cal(data, que[p] + 1, i) >=
                              from[que[p] + 1] + cal(data, que[p] + 2, i))
        ++p;
      to[i] = from[que[p]] + cal(data, que[p] + 1, i);
      while (p + 1 < q && cmp(from, que[q - 2], que[q - 1], i)) --q;
      que[q++] = i;
    }
    swap(from, to);
    cmin(ans, from[N - 1]);
  }
  cout << ans << endl;
  return 0;
}
