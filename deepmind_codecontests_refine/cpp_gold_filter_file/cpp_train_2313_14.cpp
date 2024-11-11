#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
struct BigNum {
  static const int B = 1000000000;
  vector<int> a;
  int sign;
  BigNum(long long n = 0) {
    sign = 1;
    if (n < 0) sign = -1, n *= -1;
    a.resize(0);
    if (n == 0) a.push_back(0);
    for (; n != 0; n /= B) a.push_back(n % B);
  }
  int operator[](int i) const { return a[i]; }
  void operator+=(const BigNum& other) {
    a.resize(max(a.size(), other.a.size()));
    int carry = 0;
    for (int i = (0); i < (int)(a.size()); i++) {
      int b = a[i] + carry + (i < other.a.size() ? other[i] : 0);
      a[i] = b % B;
      carry = b >= B;
    }
    if (carry == 1) a.push_back(1);
  }
  int operator%(int m) {
    long long b = 1;
    int res = 0;
    for (int i = (0); i < (int)(a.size()); i++)
      res = (b * a[i] + res) % m, b = b * B % m;
    if (sign == -1 and res != 0) res = m - res;
    return res;
  }
  void print() {
    printf("%d", a.back());
    for (int i = a.size() - 2; i > (int)(-1); i--) printf("%09d", a[i]);
    printf("\n");
  }
} ans(0);
int n, w[N], i, j, nxt[N], dif[N], pre[N];
char c[N];
struct atom {
  unsigned long long s;
  int l, h, he;
  vector<pair<int, int>> v;
  inline void clear() {
    v.clear();
    l = s = 0;
  }
  inline unsigned long long push(int x, int len) {
    ++l;
    for (; he < v.size() && v[he].first <= l - len; ++he)
      s -= 1ll * v[he].second * (v[he].first - h), h = v[he].first;
    if (he < v.size()) s -= 1ll * v[he].second * (l - len - h);
    h = l - len;
    for (; v.size() > he && (v.back().first >= l || v.back().second > x);
         v.pop_back())
      s -= 1ll *
           (v.back().first - (v.size() == he + 1 ? h : v[v.size() - 2].first)) *
           v.back().second;
    s += 1ll * x * (l - (v.size() == he ? h : v.back().first));
    v.push_back({l, x});
    return s;
  }
} a[N];
int ff[20][N], lo[N];
inline int ask(int x, int y) {
  int l = lo[y - x + 1];
  return min(ff[l][y], ff[l][x + (1 << l) - 1]);
}
int main() {
  scanf("%d", &n);
  for (i = 2; i <= n; ++i) lo[i] = lo[i >> 1] + 1;
  int m26 = 0;
  for (i = 1; i <= n; ++i) {
    scanf("%s%d", c + i, w + i);
    c[i] = (c[i] - 'a' + m26) % 26 + 'a';
    w[i] ^= ans % (1 << 30);
    ff[0][i] = w[i];
    for (j = 1; 1 << j <= i; ++j)
      ff[j][i] = min(ff[j - 1][i], ff[j - 1][i - (1 << j - 1)]);
    for (j = nxt[i - 1]; j && c[j + 1] != c[i]; j = nxt[j])
      ;
    j += i > 1 && c[j + 1] == c[i];
    nxt[i] = j;
    dif[i] = i - nxt[i];
    pre[i] = nxt[i] && dif[i] == dif[nxt[i]] ? pre[nxt[i]] : i;
    unsigned long long dt = 0;
    for (j = i; j;) {
      dt += a[pre[j]].push(ask(i - pre[j] + 1, i), (j - pre[j]) / dif[j] + 1);
      j = nxt[pre[j]];
    }
    m26 = (m26 + dt) % 26;
    ans += dt;
    ans.print();
  }
  return 0;
}
