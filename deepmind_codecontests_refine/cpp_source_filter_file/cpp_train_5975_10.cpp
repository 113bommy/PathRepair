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
struct Pt {
  int val, id;
  int operator<(const Pt& o) const { return val < o.val; }
};
int main() {
  vector<int> vec;
  vector<Pt> input;
  const int n = Rint();
  for (int i = 0; i < n; ++i) {
    int x = Rint();
    vec.push_back(x);
    input.push_back({x, i});
  }
  if (n == 1) {
    puts("YES");
    printf("%d\n%d\n", 0, vec[0]);
    return 0;
  }
  vector<int> a(n, 0), b(n, 0);
  sort((input).begin(), (input).end());
  const int T = n / 3;
  for (int i = 0; i < T; ++i) {
    a[input[i].id] = i;
    b[input[i].id] = input[i].val - i;
  }
  for (int i = T; i < 2 * T; ++i) {
    a[input[i].id] = input[i].val - i;
    b[input[i].id] = i;
  }
  for (int i = 2 * T; i < n; ++i) {
    a[input[i].id] = input[i].val - (n - 1 - i);
    b[input[i].id] = n - 1 - i;
  }
  puts("YES");
  for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
    printf("%d ", it);
  puts("");
  for (__typeof((b).begin()) it = (b).begin(); it != (b).end(); ++it)
    printf("%d ", it);
  puts("");
  return 0;
  return 0;
}
