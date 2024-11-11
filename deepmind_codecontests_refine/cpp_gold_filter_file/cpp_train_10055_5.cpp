#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << '\n'; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
template <class T>
bool umax(T &a, T b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T>
bool umin(T &a, T b) {
  return (a > b ? a = b, 1 : 0);
}
const int N = 2e5 + 2;
const int K = 900;
void add(int *a, int v, int x) {
  v++;
  while (v < N) {
    a[v] += x;
    v += v & -v;
  }
}
int get(int *a, int v) {
  v++;
  int ans = 0;
  while (v > 0) {
    ans += a[v];
    v -= v & -v;
  }
  return ans;
}
struct {
  int a[K];
  int fnw[N];
  int n;
  int cl;
  int countlower(int x) { return get(fnw, x - 1); }
  int countgreater(int x) { return cl - get(fnw, x); }
} my[N / K + 1];
long long ans = 0;
int d1 = -1, d2 = -1;
void add(int i, int mn) {
  int b = i / K;
  for (int j = 0; j <= N / K; j++) {
    if (j < b) {
      ans -= mn * my[j].countgreater(my[b].a[i % K]);
    } else if (j == b) {
      for (int t = 0; t < my[j].n; t++) {
        if (t + j * K == d1 || t + j * K == d2 || t + j * K == i % K) continue;
        if (t < i % K) {
          ans -= mn * (my[j].a[t] > my[j].a[i % K]);
        } else {
          ans -= mn * (my[j].a[t] < my[j].a[i % K]);
        }
      }
    } else {
      ans -= mn * my[j].countlower(my[b].a[i % K]);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    my[i / K].n++;
    my[i / K].cl++;
    my[i / K].a[i % K] = i + 1;
    add(my[i / K].fnw, i + 1, 1);
  }
  while (q--) {
    int i, j;
    cin >> i >> j;
    --i;
    --j;
    add(i, 1);
    add(my[i / K].fnw, my[i / K].a[i % K], -1);
    my[i / K].cl--;
    d1 = i;
    add(j, 1);
    add(my[j / K].fnw, my[j / K].a[j % K], -1);
    my[j / K].cl--;
    d2 = j;
    swap(my[i / K].a[i % K], my[j / K].a[j % K]);
    add(i, -1);
    add(my[i / K].fnw, my[i / K].a[i % K], 1);
    my[i / K].cl++;
    d1 = -1;
    add(j, -1);
    add(my[j / K].fnw, my[j / K].a[j % K], 1);
    my[j / K].cl++;
    d2 = -1;
    cout << ans << '\n';
  }
  return 0;
}
