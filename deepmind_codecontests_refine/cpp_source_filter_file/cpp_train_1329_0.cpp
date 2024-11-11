//#define _GLIBCXX_DEBUG
#include <cstdio>
#include <cstdint>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

const unsigned int mod = 998244353;

struct mint {
  unsigned int x;
  mint():x(0) {}
  mint(int64_t x_) {
    int64_t v = int64_t(x_ % mod);
    if(v < 0) v += mod;
    x = (unsigned int)v;
  }
  static mint row(int v) {
    mint v_;
    v_.x = v;
    return v_;
  }
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    u_int64_t z = x;
    z *= a.x;
    x = (unsigned int)(z % mod);
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  friend bool operator==(const mint &a, const mint &b) {return a.x == b.x;}
  friend bool operator!=(const mint &a, const mint &b) {return a.x != b.x;}
  mint &operator++() {
    x++;
    if(x == mod) x = 0;
    return *this;
  }
  mint &operator--() {
    if(x == 0) x = mod;
    x--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }
  mint pow(int64_t t) const {
    mint x_ = *this, r = 1;
    while(t) {
      if(t&1) r *= x_;
      x_ *= x_;
      t >>= 1;
    }
    return r;
  }
  //for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) {return mint(*this) /= a;}
};

#define N 200100

//head

int n, k;
int p[N];
mint u[N], _u[N];
mint ans;
mint bit1[N], bit2[N];
void add(int i, mint x, mint *bit) {
  while(i <= n) {
    bit[i] += x;
    i += i&-i;
  }
}
mint sum(int i, mint *bit) {
  mint res;
  while(i) {
    res += bit[i];
    i &= i-1;
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &k);
  rep(i, n) scanf("%d", p+i);
  const mint g = mint(k-1)/k, _g = g.inv(), gg = mint(2).inv();
  u[0] = _u[0] = 1;
  rep(i, n-1) {
    if(i < k-1) {
      u[i+1] = u[i];
      _u[i+1] = _u[i];
    }
    else {
      u[i+1] = u[i]*g;
      _u[i+1] = _u[i]*_g;
    }
  }
  rep(i, n) {
    ans += sum(p[i], bit1)*gg*u[i];
    ans -= sum(p[i], bit2)-i;
    ans -= (sum(n, bit1)-sum(p[i], bit1))*gg*u[i];
    add(p[i], _u[i], bit1);
    add(p[i], 1, bit2);
  }
  printf("%d\n", ans.x);
}