#include <bits/stdc++.h>
using namespace std;
const int MAX_MEM = (int)1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void *operator new(size_t n) {
  char *res = mem + mpos;
  mpos += n;
  return (void *)res;
}
inline void operator delete(void *) {}
struct __io_dev {
  __io_dev(const bool &__fastio = false) {
    if (__fastio) ios_base::sync_with_stdio(false), cin.tie(nullptr);
    srand(time(nullptr));
    if (!string("").empty())
      freopen(
          ""
          ".in",
          "r", stdin),
          freopen(
              ""
              ".out",
              "w", stdout);
  }
  ~__io_dev() { fprintf(stderr, "%.6f ms\n", 1e3 * clock() / CLOCKS_PER_SEC); }
} __io(false);
const long long inf = (long long)1e+9 + 7ll;
const long long linf = (long long)1e+18 + 7ll;
const long double eps = (long double)1e-9;
const long double pi = acosl((long double)-1.0);
const int alph = 26;
const int maxs = 512l;
static char buff[(int)2e6 + 17];
long long __p[3] = {29ll, 31ll, 33ll};
long long __mod[3] = {inf, inf + 2ll, 14881337ll};
const int maxn = (int)2e5 + 17;
int n;
long long a[maxn];
vector<long long> ans;
set<long long> s;
int main() {
  scanf("%d", &n);
  for (long long i = 0ll; i < (long long)n; ++i) {
    scanf("%lld", a + i);
    s.insert(a[i]);
  }
  for (; !s.empty();) {
    long long x = *(--s.end());
    long long lst = x;
    for (; x > 0; x >>= 1)
      if (s.find(x) == s.end()) {
        s.erase(lst);
        s.insert(x);
        break;
      }
    if (x == 0) {
      s.erase(lst);
      ans.push_back(lst);
    }
  }
  for (long long i = 0ll; i < (long long)n; ++i) printf("%lld ", ans[i]);
  return 0;
}
