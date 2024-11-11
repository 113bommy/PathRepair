#include <bits/stdc++.h>
using namespace std;
bool debug;
const int inf = 1e9 + 5;
const int nax = 2e5 + 5;
const int czapa = 262144;
const int BLOK = 20000;
const double PI = 3.1415926535897932384626433832795;
struct zespo {
  double re, im;
  zespo(double r = 0., double i = 0.) : re(r), im(i) {}
  zespo operator+(zespo const& x) const { return zespo(re + x.re, im + x.im); }
  zespo operator-(zespo const& x) const { return zespo(re - x.re, im - x.im); }
  zespo operator*(zespo const& x) const {
    return zespo(re * x.re - im * x.im, re * x.im + im * x.re);
  }
  zespo operator/(double d) const { return zespo(re / d, im / d); }
};
void fft(zespo* a, bool rev, int n) {
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double kat = 2.0 * PI / len * (rev ? -1 : 1);
    zespo pierw(cos(kat), sin(kat));
    for (int i = 0; i < n; i += len) {
      zespo w(1, 0);
      for (int j = 0; j < len / 2; ++j) {
        zespo u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w = w * pierw;
      }
    }
  }
  if (rev)
    for (int i = 0; i < n; i++) a[i] = a[i] / n;
}
unsigned int bitya[nax], bityb[nax];
unsigned int vala[32][1 << 13], valb[32][1 << 13];
char a[nax + 100], b[nax + 100];
int wyn[2 * nax], bocz[2 * nax], cnt[1 << 16], l[2 * nax], p[2 * nax],
    pocza[2 * nax], val[nax];
int dla, dlb;
void bituj() {
  for (int i = 0; i <= (1 << 16) - 1; ++i) cnt[i] = __builtin_popcount(i);
  for (int i = 0; i <= (32) - 1; ++i) bitya[0] = (bitya[0] << 1) + a[i];
  for (int i = 1; i <= dla - 1; ++i) bitya[i] = (bitya[i - 1] << 1) + a[i + 31];
  for (int i = 0; i <= (32) - 1; ++i) bityb[0] = (bityb[0] << 1) + b[i];
  for (int i = 1; i <= dlb - 1; ++i) bityb[i] = (bityb[i - 1] << 1) + b[i + 31];
  for (int i = 0; i <= (dla)-1; ++i) vala[i % 32][i / 32] = bitya[i];
  for (int i = 0; i <= (dlb)-1; ++i) valb[i % 32][i / 32] = bityb[i];
}
int pc(unsigned int x) { return cnt[x >> 16] + cnt[x & 65535]; }
int bit_query(int p1, int p2, int len) {
  int res = 0;
  int r = len % 32;
  int r1 = p1 % 32;
  int r2 = p2 % 32;
  int ile = len / 32;
  p1 /= 32;
  p2 /= 32;
  for (int i = 0; i <= (ile)-1; ++i)
    res += pc(vala[r1][p1 + i] ^ valb[r2][p2 + i]);
  if (r) res += pc((vala[r1][p1 + ile] ^ valb[r2][p2 + ile]) >> (32 - r));
  return res;
}
int q, p1, p2, len;
zespo zb[czapa], za[czapa];
int main(int argc, char* argv[]) {
  scanf(" %s %s", a, b);
  dla = strlen(a);
  dlb = strlen(b);
  for (int i = 0; i <= (dla)-1; ++i) a[i] -= '0';
  for (int i = 0; i <= (dlb)-1; ++i) b[i] -= '0';
  bituj();
  scanf("%d", &q);
  for (int i = 0; i <= (q)-1; ++i) {
    scanf("%d%d%d", &p1, &p2, &len);
    if (len <= BLOK)
      wyn[i] = bit_query(p1, p2, len);
    else {
      l[i] = ((p2 + BLOK - 1) / BLOK);
      p[i] = ((p2 + len) / BLOK);
      pocza[i] = p1 + l[i] * BLOK - p2;
      int x = p2 + len - p[i] * BLOK;
      bocz[i] = bit_query(p1, p2, l[i] * BLOK - p2) +
                bit_query(p1 + len - x, p[i] * BLOK, x);
      wyn[i] = (p[i] - l[i]) * BLOK;
    }
  }
  for (int i = 0; i <= (dla)-1; ++i) za[i] = a[i] ? zespo(1, 0) : zespo(-1, 0);
  fft(za, false, czapa);
  for (int i = 0; i <= (dlb / BLOK) - 1; ++i) {
    for (int j = 0; j <= (czapa)-1; ++j) zb[j] = zespo(0, 0);
    for (int j = 0; j <= (BLOK)-1; ++j)
      zb[j] = b[i * BLOK + j] ? zespo(1, 0) : zespo(-1, 0);
    reverse(zb, zb + BLOK);
    fft(zb, false, czapa);
    for (int j = 0; j <= (czapa)-1; ++j) zb[j] = zb[j] * za[j];
    fft(zb, true, czapa);
    for (int j = BLOK - 1; j <= dla - 1; ++j)
      val[j - BLOK + 1] = int(round(zb[j].re));
    for (int j = 0; j <= (q)-1; ++j)
      if (l[j] < p[j] && l[j] == i) {
        wyn[j] -= val[pocza[j]];
        pocza[j] += BLOK;
        ++l[j];
      }
  }
  for (int i = 0; i <= (q)-1; ++i) printf("%d\n", wyn[i] / 2 + bocz[i]);
  return 0;
}
