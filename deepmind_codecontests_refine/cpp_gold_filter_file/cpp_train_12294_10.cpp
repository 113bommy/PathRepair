#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ld = long double;
using ll = long long;
constexpr int mod = 998244353;
constexpr int odw2 = (mod + 1) / 2;
void OdejmijOd(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int Odejmij(int a, int b) {
  OdejmijOd(a, b);
  return a;
}
void DodajDo(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int Dodaj(int a, int b) {
  DodajDo(a, b);
  return a;
}
int Mnoz(int a, int b) { return (ll)a * b % mod; }
void MnozDo(int& a, int b) { a = Mnoz(a, b); }
int Pot(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2 == 1) MnozDo(res, a);
    a = Mnoz(a, a);
    b /= 2;
  }
  return res;
}
int Odw(int a) { return Pot(a, mod - 2); }
void PodzielDo(int& a, int b) { MnozDo(a, Odw(b)); }
int Podziel(int a, int b) { return Mnoz(a, Odw(b)); }
int Moduluj(ll x) {
  x %= mod;
  if (x < 0) x += mod;
  return x;
}
template <typename T>
T Maxi(T& a, T b) {
  return a = max(a, b);
}
template <typename T>
T Mini(T& a, T b) {
  return a = min(a, b);
}
namespace fft {
typedef double ld;
struct C {
  ld real, imag;
  C operator*(const C& he) const {
    return C{real * he.real - imag * he.imag, real * he.imag + imag * he.real};
  }
  void operator+=(const C& he) {
    real += he.real;
    imag += he.imag;
  }
};
void dft(vector<C>& a, bool rev) {
  const int n = a.size();
  for (int i = 1, k = 0; i < n; ++i) {
    for (int bit = n / 2; (k ^= bit) < bit; bit /= 2)
      ;
    ;
    ;
    if (i < k) swap(a[i], a[k]);
  }
  for (int len = 1, who = 0; len < n; len *= 2, ++who) {
    static vector<C> t[30];
    vector<C>& om = t[who];
    if (om.empty()) {
      om.resize(len);
      const ld ang = 2 * acosl(0) / len;
      for (int i = 0; i < int(len); ++i)
        om[i] =
            i % 2 || !who ? C{cos(i * ang), sin(i * ang)} : t[who - 1][i / 2];
    }
    for (int i = 0; i < n; i += 2 * len)
      for (int k = 0; k < int(len); ++k) {
        const C x = a[i + k],
                y = a[i + k + len] * C{om[k].real, om[k].imag * (rev ? -1 : 1)};
        a[i + k] += y;
        a[i + k + len] = C{x.real - y.real, x.imag - y.imag};
      }
  }
  if (rev)
    for (int i = 0; i < int(n); ++i) a[i].real /= n;
}
template <typename T>
vector<T> multiply(const vector<T>& a, const vector<T>& b, bool split = false,
                   bool normalize = false) {
  if (a.empty() || b.empty()) return {};
  T big = 0;
  if (normalize) {
    assert(a.size() == b.size());
    for (T x : a) big = max(big, x);
    for (T x : b) big = max(big, x);
    big /= 2;
  }
  int n = a.size() + b.size();
  vector<T> ans(n - 1);
  while (n & (n - 1)) ++n;
  auto speed = [&](const vector<C>& w, int i, int k) {
    int j = i ? n - i : 0, r = k ? -1 : 1;
    return C{w[i].real + w[j].real * r, w[i].imag - w[j].imag * r} *
           (k ? C{0, -0.5} : C{0.5, 0});
  };
  if (!split) {
    vector<C> in(n), done(n);
    for (int i = 0; i < int(a.size()); ++i) in[i].real = a[i] - big;
    for (int i = 0; i < int(b.size()); ++i) in[i].imag = b[i] - big;
    dft(in, false);
    for (int i = 0; i < int(n); ++i)
      done[i] = speed(in, i, 0) * speed(in, i, 1);
    dft(done, true);
    for (int i = 0; i < int(ans.size()); ++i)
      ans[i] = is_integral<T>::value ? llround(done[i].real) : done[i].real;
  } else {
    const T M = 1 << 15;
    vector<C> t[2];
    for (int x = 0; x < int(2); ++x) {
      t[x].resize(n);
      auto& in = x ? b : a;
      for (int i = 0; i < int(in.size()); ++i)
        t[x][i] = C{ld(in[i] % M), ld(in[i] / M)};
      dft(t[x], false);
    }
    T mul = 1;
    for (int s = 0; s < 3; ++s, mul *= M) {
      vector<C> prod(n);
      for (int x = 0; x < int(2); ++x)
        for (int y = 0; y < int(2); ++y)
          if (x + y == s)
            for (int i = 0; i < int(n); ++i)
              prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
      dft(prod, true);
      for (int i = 0; i < int(ans.size()); ++i)
        ans[i] += llround(prod[i].real) % mod * mul;
    }
  }
  if (normalize) {
    T so_far = 0;
    for (int i = 0; i < int(ans.size()); ++i) {
      if (i < (int)a.size())
        so_far += a[i] + b[i];
      else
        so_far -= a[i - a.size()] + b[i - a.size()];
      ans[i] += big * so_far - big * big * min(i + 1, (int)ans.size() - i);
    }
  }
  return ans;
}
const ll M = 1 << 17;
vector<ll> compress(const vector<ll>& a) {
  vector<ll> tmp((a.size() + 1) / 2);
  for (int i = 0; 2 * i + 1 < (int)a.size(); ++i)
    tmp[i] += a[2 * i] + a[2 * i + 1] * M;
  if (a.size() % 2) tmp.back() = a.back();
  return tmp;
}
vector<ll> my_mul(const vector<ll>& a, const vector<ll>& b) {
  vector<ll> tmp = multiply(compress(a), compress(b), false);
  vector<ll> r(2 * tmp.size() + 1);
  for (int i = 0; i < (int)tmp.size(); ++i) {
    r[2 * i] += tmp[i] % M;
    r[2 * i + 1] += tmp[i] / M % M;
    r[2 * i + 2] += tmp[i] / M / M;
  }
  r.resize(a.size() + b.size() - 1);
  return r;
}
}  // namespace fft
vector<int> Pomnoz(const vector<int>& a, const vector<int>& b) {
  vector<ll> A;
  A.reserve(a.size());
  for (int x : a) A.push_back(x);
  vector<ll> B;
  B.reserve(b.size());
  for (int x : b) B.push_back(x);
  vector<ll> res = fft::multiply(A, B, true);
  vector<int> wyn;
  wyn.reserve(res.size());
  for (ll x : res) {
    wyn.push_back(Moduluj(x));
  }
  return wyn;
}
void DodajDo(vector<int>& a, const vector<int>& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int)b.size(); i++) {
    DodajDo(a[i], b[i]);
  }
}
struct Zlaczacz {
  vector<int> wynik;
  const vector<vector<int>>& wyniki;
  pair<vector<int>, vector<int>> Ogarnij(int a, int b) {
    pair<vector<int>, vector<int>> res;
    if (a == b) {
      res.first = wyniki[a];
      res.second = wyniki[a];
      debug() << "Zlaczacz::Ogarnij("
                 " ["
                 "a"
                 ": "
              << (a)
              << "] "
                 " ["
                 "b"
                 ": "
              << (b)
              << "] "
                 ") = "
              << res;
      return res;
    }
    const int c = (a + b) / 2;
    auto left = Ogarnij(a, c);
    auto right = Ogarnij(c + 1, b);
    res.first = Pomnoz(left.first, right.first);
    res.second = left.second;
    DodajDo(res.second, Pomnoz(left.first, right.second));
    debug() << "Zlaczacz::Ogarnij("
               " ["
               "a"
               ": "
            << (a)
            << "] "
               " ["
               "b"
               ": "
            << (b)
            << "] "
               ") = "
            << res;
    return res;
  }
  Zlaczacz(const vector<vector<int>>& wyniki_) : wyniki(wyniki_) {
    wynik = Ogarnij(0, (int)wyniki.size() - 1).second;
    DodajDo(wynik, vector<int>{1});
  }
};
constexpr int nax = 100 * 1000 + 105;
vector<int> drz[nax];
vector<int> Ogarnij(int w) {
  const int orig_w = w;
  vector<vector<int>> wyniki;
  while (!drz[w].empty()) {
    if ((int)drz[w].size() == 1) {
      wyniki.push_back(vector<int>{0, 1});
    } else if ((int)drz[w].size() == 2) {
      wyniki.push_back(Ogarnij(drz[w][1]));
      wyniki.back().insert(wyniki.back().begin(), 0);
    } else {
      assert(false);
    }
    w = drz[w][0];
  }
  wyniki.push_back(vector<int>{0, 1});
  debug() << " ["
             "orig_w"
             ": "
          << (orig_w)
          << "] "
             " ["
             "wyniki"
             ": "
          << (wyniki) << "] ";
  Zlaczacz res(wyniki);
  debug() << "Ogarnij("
             " ["
             "orig_w"
             ": "
          << (orig_w)
          << "] "
             ") = "
          << res.wynik;
  return res.wynik;
}
int roz[nax];
void Dfs(int w, int o) {
  for (int i = 0; i < (int)drz[w].size(); i++) {
    if (drz[w][i] == o) {
      swap(drz[w][i], drz[w].back());
      drz[w].pop_back();
      break;
    }
  }
  roz[w] = 1;
  for (int x : drz[w]) {
    Dfs(x, w);
    roz[w] += roz[x];
  }
  sort(drz[w].begin(), drz[w].end(),
       [](int a, int b) -> bool { return roz[a] > roz[b]; });
  debug() << " ["
             "w"
             ": "
          << (w)
          << "] "
             " ["
             "drz[w]"
             ": "
          << (drz[w]) << "] ";
}
constexpr int skok = 1024;
int sil[mod / skok + 105];
int PreprocSil(int n) {
  assert(0 <= n and n < mod);
  int ilo = sil[n / skok];
  for (int i = (n / skok) * skok + 1; i <= n; i++) {
    MnozDo(ilo, i);
  }
  return ilo;
}
pair<int, int> Silnia(ll n) {
  if (n < mod) {
    return {0, PreprocSil(n)};
  }
  auto res = Silnia(n / mod);
  res.first += n / mod;
  MnozDo(res.second, PreprocSil(n % mod));
  return res;
}
int C(ll n, int k) {
  if (!(0 <= k and k <= n)) {
    return 0;
  }
  auto p = Silnia(n);
  auto m1 = Silnia(n - k);
  auto m2 = Silnia(k);
  assert(p.first >= m1.first + m2.first);
  if (p.first > m1.first + m2.first) {
    return 0;
  }
  if ((n / mod) % 2 == 1) {
    p.second = Odejmij(0, p.second);
  }
  return Podziel(p.second, Mnoz(m1.second, m2.second));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ll x;
  cin >> n >> x;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    drz[a].push_back(b);
    drz[b].push_back(a);
  }
  Dfs(1, -1);
  vector<int> res = Ogarnij(1);
  debug() << " ["
             "res"
             ": "
          << (res) << "] ";
  int wyn = 0;
  int c = 1;
  for (int i = 1; i < (int)res.size(); i++) {
    if (i > 1) {
      MnozDo(c, Podziel(Moduluj(x + i - 1), i - 1));
    }
    DodajDo(wyn, Mnoz(res[i], c));
  }
  cout << wyn << endl;
  return 0;
}
