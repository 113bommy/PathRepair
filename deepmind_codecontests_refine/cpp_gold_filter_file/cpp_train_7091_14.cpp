#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void rd(T& x) {
  int f = 0, c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  if (f) x = -x;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) {
  rd(x);
  rd(args...);
}
template <typename T>
void we(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) we(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
void ws(T x) {
  we(x);
  putchar(' ');
}
template <typename T>
void wln(T x) {
  we(x);
  puts("");
}
template <typename T, typename... Args>
inline void wln(const T& x, const Args&... args) {
  ws(x);
  if (sizeof...(args) > 1)
    ws(args...);
  else
    wln(args...);
}
template <typename T>
inline bool cmin(T& x, const T& y) {
  return y < x ? (x = y, true) : false;
}
template <typename T>
inline bool cmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
const int maxn = (int)3e5 + 10;
const long long inf = (long long)1e18;
const long long mod = (long long)12345;
long long pw(long long a, long long b) {
  a %= mod;
  long long r = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) r = r * a % mod;
  return r;
}
vector<vector<long long> > iden(int n) {
  vector<vector<long long> > r =
      vector<vector<long long> >(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) r[i][i] = 1;
  return r;
}
vector<vector<long long> > mul(vector<vector<long long> > a,
                               vector<vector<long long> > b, int m) {
  vector<vector<long long> > r = vector<vector<long long> >(
      (int)a.size(), vector<long long>((int)b[0].size(), 0));
  for (int i = (0); i < ((int)a.size()); i++)
    for (int j = (0); j < ((int)b[0].size()); j++)
      for (int k = (0); k < ((int)a[0].size()); k++) {
        r[i][j] += a[i][k] * b[k][j] % m;
        if (r[i][j] >= m) r[i][j] -= m;
      }
  return r;
}
vector<vector<long long> > pw(vector<vector<long long> > a, long long b,
                              int m) {
  vector<vector<long long> > r = iden((int)a.size());
  for (; b; b >>= 1, a = mul(a, a, m))
    if (b & 1) r = mul(r, a, m);
  return r;
}
long long n, c, ans;
struct Elem {
  vector<int> v;
  Elem() { v = vector<int>(26, 0); }
  bool operator<(const Elem& e) const {
    for (int i = (0); i < (25); i++) {
      if (v[i] == e.v[i]) continue;
      return v[i] < e.v[i];
    }
    return v[25] < e.v[25];
  }
};
map<Elem, int> maps;
vector<int> v[26];
int pdt[1001];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main() {
  rd(n, c);
  for (int i = (0); i < (c); i++) {
    char ch = getchar();
    int x;
    rd(x);
    if (!pdt[ch - 'A'])
      pdt[ch - 'A'] = x;
    else
      pdt[ch - 'A'] = lcm(pdt[ch - 'A'], x);
    v[ch - 'A'].push_back(x);
  }
  if (!n) return puts("1"), 0;
  if (!c) return puts("0"), 0;
  for (int iA = (0); iA < (pdt[0] ? pdt[0] : 1); iA++)
    for (int iB = (0); iB < (pdt[1] ? pdt[1] : 1); iB++)
      for (int iC = (0); iC < (pdt[2] ? pdt[2] : 1); iC++)
        for (int iD = (0); iD < (pdt[3] ? pdt[3] : 1); iD++)
          for (int iE = (0); iE < (pdt[4] ? pdt[4] : 1); iE++)
            for (int iF = (0); iF < (pdt[5] ? pdt[5] : 1); iF++)
              for (int iG = (0); iG < (pdt[6] ? pdt[6] : 1); iG++)
                for (int iH = (0); iH < (pdt[7] ? pdt[7] : 1); iH++)
                  for (int iI = (0); iI < (pdt[8] ? pdt[8] : 1); iI++)
                    for (int iJ = (0); iJ < (pdt[9] ? pdt[9] : 1); iJ++)
                      for (int iK = (0); iK < (pdt[10] ? pdt[10] : 1); iK++)
                        for (int iL = (0); iL < (pdt[11] ? pdt[11] : 1); iL++)
                          for (int iM = (0); iM < (pdt[12] ? pdt[12] : 1); iM++)
                            for (int iN = (0); iN < (pdt[13] ? pdt[13] : 1);
                                 iN++)
                              for (int iO = (0); iO < (pdt[14] ? pdt[14] : 1);
                                   iO++)
                                for (int iP = (0); iP < (pdt[15] ? pdt[15] : 1);
                                     iP++)
                                  for (int iQ = (0);
                                       iQ < (pdt[16] ? pdt[16] : 1); iQ++)
                                    for (int iR = (0);
                                         iR < (pdt[17] ? pdt[17] : 1); iR++)
                                      for (int iS = (0);
                                           iS < (pdt[18] ? pdt[18] : 1); iS++)
                                        for (int iT = (0);
                                             iT < (pdt[19] ? pdt[19] : 1); iT++)
                                          for (int iU = (0);
                                               iU < (pdt[20] ? pdt[20] : 1);
                                               iU++)
                                            for (int iV = (0);
                                                 iV < (pdt[21] ? pdt[21] : 1);
                                                 iV++)
                                              for (int iW = (0);
                                                   iW < (pdt[22] ? pdt[22] : 1);
                                                   iW++)
                                                for (int iX = (0);
                                                     iX <
                                                     (pdt[23] ? pdt[23] : 1);
                                                     iX++)
                                                  for (int iY = (0);
                                                       iY <
                                                       (pdt[24] ? pdt[24] : 1);
                                                       iY++)
                                                    for (int iZ = (0);
                                                         iZ < (pdt[25] ? pdt[25]
                                                                       : 1);
                                                         iZ++) {
                                                      Elem now;
                                                      now.v[0] = iA;
                                                      now.v[1] = iB;
                                                      now.v[2] = iC;
                                                      now.v[3] = iD;
                                                      now.v[4] = iE;
                                                      now.v[5] = iF;
                                                      now.v[6] = iG;
                                                      now.v[7] = iH;
                                                      now.v[8] = iI;
                                                      now.v[9] = iJ;
                                                      now.v[10] = iK;
                                                      now.v[11] = iL;
                                                      now.v[12] = iM;
                                                      now.v[13] = iN;
                                                      now.v[14] = iO;
                                                      now.v[15] = iP;
                                                      now.v[16] = iQ;
                                                      now.v[17] = iR;
                                                      now.v[18] = iS;
                                                      now.v[19] = iT;
                                                      now.v[20] = iU;
                                                      now.v[21] = iV;
                                                      now.v[22] = iW;
                                                      now.v[23] = iX;
                                                      now.v[24] = iY;
                                                      now.v[25] = iZ;
                                                      maps.insert(make_pair(
                                                          now,
                                                          (int)maps.size()));
                                                    }
  vector<vector<long long> > m((int)maps.size(),
                               vector<long long>((int)maps.size(), 0));
  for (auto& i : maps) {
    for (int j = (0); j < (26); j++) {
      if (pdt[j]) {
        Elem now = i.first;
        now.v[j] = (now.v[j] + 1) % pdt[j];
        m[i.second][maps.find(now)->second]++;
      }
    }
  }
  m = pw(m, n, mod);
  for (auto& i : maps) {
    const Elem& now = i.first;
    bool fail = 0;
    for (int j = (0); j < (26); j++) {
      if (!pdt[j]) continue;
      bool fnd = 0;
      for (auto& k : v[j]) {
        if (now.v[j] % k == 0) {
          fnd = 1;
          break;
        }
      }
      if (!fnd) {
        fail = 1;
        break;
      }
    }
    if (!fail) ans = (ans + m[0][i.second]) % mod;
  }
  wln(ans);
}
