#include <bits/stdc++.h>
using namespace std;
int ni() {
  int val;
  scanf("%i", &val);
  return val;
}
pair<int, int> npi() {
  pair<int, int> val;
  scanf("%i %i", &val.first, &val.second);
  return val;
}
int64_t nll() {
  int64_t val;
  scanf("%I64d", &val);
  return val;
}
vector<int> nvi(int n, int corr = 0) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = ni() + corr;
  return move(a);
}
char nc() {
  char val;
  do {
    val = getchar();
  } while (val == ' ' || val == '\r' || val == '\n');
  return val;
}
char ncs() {
  char val;
  do {
    val = getchar();
  } while (false);
  return val;
}
string ns() {
  static char buff[1024 * 4000];
  scanf("%s", buff);
  return string{buff};
}
int64_t gcd(int64_t a, int64_t b) {
  while (b) {
    auto tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int64_t tr2(int xv1, int yv1, int xv2, int yv2, int x3, int y3) {
  return 1LL * (xv2 - xv1) * (y3 - yv1) - 1LL * (yv2 - yv1) * (x3 - xv1);
}
const long double eps = 1e-12;
const long double pi = acos(-1.0);
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
int8_t bits_cnt[256];
vector<bool> prime;
vector<int> primes;
const string input_dir = "inputs\\";
string input_file = input_dir + "input.txt";
string output_file = input_dir + "output.txt";
void init_streams() {}
void init_data() {
  bits_cnt[0] = 0;
  for (int i = 1; i <= 255; ++i)
    for (int j = 0; j < 8; ++j)
      if ((1 << j) & i) ++bits_cnt[i];
  const int maxn = 200 * 1000 + 7;
  prime.assign(maxn, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i < maxn; ++i) {
    if (!prime[i]) continue;
    primes.emplace_back(i);
    for (int j = i + i; j < maxn; j += i) prime[j] = false;
  }
}
int get_bit_count(int v) {
  return bits_cnt[v & 0xFF] + bits_cnt[(v >> 8) & 0xFF] +
         bits_cnt[(v >> 16) & 0xFF] + bits_cnt[(v >> 24) & 0xFF];
}
const int md = 1000000000 + 7;
int64_t t = 0;
inline void mul_t(int64_t& v) {
  v *= t;
  v %= md;
}
inline void mul(int64_t& v, int64_t fv) {
  v *= fv;
  v %= md;
}
inline void add(int64_t& v, int64_t fv) {
  v += fv;
  if (v >= md) v -= md;
}
vector<int64_t> mem;
vector<int64_t> mem_sz;
int64_t f(int n) {
  int64_t ans = 0;
  while (n > 1) {
    int64_t addv = 0;
    int gr_sz = n;
    if (mem[n] < 0) {
      auto ub = int(sqrt(n));
      for (auto it = primes.begin(); it != primes.end() && *it <= ub; ++it) {
        if (n % (*it) == 0) {
          gr_sz = (*it);
          break;
        }
      }
      if (gr_sz > 0) {
        int64_t grc = n / gr_sz;
        int64_t mv = (gr_sz * (gr_sz - 1) / 2) % md;
        addv = (grc * mv) % md;
      }
      mem[n] = addv;
      mem_sz[n] = gr_sz;
    }
    add(ans, mem[n]);
    n = n / mem_sz[n];
  }
  return ans;
}
int main() {
  init_streams();
  init_data();
  t = nll();
  auto l = nll(), r = nll();
  mem.assign(6 * 1000 * 1000, -1);
  mem_sz.assign(6 * 1000 * 1000, -1);
  int64_t ans = 0;
  int64_t tm = 1;
  for (int arg = l, pw = 0; arg <= r; ++arg, mul_t(tm)) {
    auto fv = f(arg);
    mul(fv, tm);
    add(ans, fv);
  }
  cout << ans << endl;
  return 0;
}
