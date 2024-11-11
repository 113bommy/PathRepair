#include <bits/stdc++.h>
using namespace std;
struct IO {
} io;
IO &operator>>(IO &io, int &n) {
  scanf("%d", &n);
  return io;
}
IO &operator>>(IO &io, unsigned int &n) {
  scanf("%u", &n);
  return io;
}
IO &operator>>(IO &io, long long &n) {
  scanf("%lld", &n);
  return io;
}
IO &operator>>(IO &io, unsigned long long &n) {
  scanf("%llu", &n);
  return io;
}
IO &operator>>(IO &io, double &n) {
  scanf("%lf", &n);
  return io;
}
IO &operator>>(IO &io, long double &n) {
  scanf("%Lf", &n);
  return io;
}
IO &operator>>(IO &io, char *c) {
  scanf("%s", c);
  return io;
}
IO &operator<<(IO &io, const int &n) {
  printf("%d", n);
  return io;
}
IO &operator<<(IO &io, const unsigned int &n) {
  printf("%u", n);
  return io;
}
IO &operator<<(IO &io, const long long &n) {
  printf("%lld", n);
  return io;
}
IO &operator<<(IO &io, const unsigned long long &n) {
  printf("%llu", n);
  return io;
}
IO &operator<<(IO &io, const double &n) {
  printf("%lf", n);
  return io;
}
IO &operator<<(IO &io, const long double &n) {
  printf("%Lf", n);
  return io;
}
IO &operator<<(IO &io, const char c[]) {
  printf("%s", c);
  return io;
}
template <class U, class S, class T>
U &operator<<(U &os, const pair<S, T> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class U, class T>
U &operator<<(U &os, const vector<T> &x) {
  os << "[";
  for (int i = 0; i < (int)(x.size()); ++i) {
    os << x[i];
    if (i != x.size() - 1) os << ",";
  }
  os << "]";
  return os;
}
template <class U, class T>
U &operator<<(U &os, const set<T> &x) {
  os << "[";
  for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it) {
    os << *it;
    if (++it != x.end()) os << ",";
    it--;
  }
  os << "]";
  return os;
}
template <class U, class S, class T>
U &operator<<(U &os, const map<S, T> &x) {
  os << "[";
  for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it) {
    os << *it;
    if (++it != x.end()) os << ",";
    it--;
  }
  os << "]";
  return os;
}
void printBit(int b, int k = -1) {
  if (k == -1) {
    int bb = 1, i = 0;
    while (bb) {
      if (b & bb) k = i;
      bb <<= 1;
      i++;
    }
  }
  for (int ct = 0; ct < (int)(k); ++ct) {
    cout << b % 2;
    b >>= 1;
  }
  cout << "\n";
}
double EPS = 1e-10;
double dp[210][210][70];
bool vis[70];
int hp0, dt0, l0, r0, p0;
int hp1, dt1, l1, r1, p1;
vector<pair<int, int> > d;
vector<double> alpha, beta;
double calc(int h0, int h1, int t) {
  if (vis[t]) return dp[h0][h1][t];
  vis[t] = true;
  if (alpha[t] < EPS) return dp[h0][h1][t] = beta[t];
  return dp[h0][h1][t] = alpha[t] * calc(h0, h1, (t + 1) % d.size()) + beta[t];
}
int main() {
  cin >> hp0 >> dt0 >> l0 >> r0 >> p0;
  cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
  if (p0 == 100) {
    cout << 0 << "\n";
    return 0;
  }
  if (p1 == 100) {
    if (p0 == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
    return 0;
  }
  for (int i = 0; i < (int)(dt1); ++i) d.push_back(make_pair(i * dt0, 0));
  for (int i = 0; i < (int)(dt0); ++i) d.push_back(make_pair(i * dt1, 1));
  sort((d).begin(), (d).end());
  const int D = d.size();
  for (int h0 = 0; h0 <= hp0; h0++) {
    for (int h1 = 0; h1 <= hp1; h1++) {
      if (h1 == 0) {
        for (int t = 0; t < (int)(d.size()); ++t) dp[h0][h1][t] = 1.0;
      } else if (h0 == 0) {
        for (int t = 0; t < (int)(d.size()); ++t) dp[h0][h1][t] = 0.0;
      } else {
        alpha.clear();
        beta.clear();
        for (int t = 0; t < (int)(D); ++t) {
          int t2 = (t + 1) % D;
          if (d[t].second == 0) {
            double pp = (double)p0 / 100;
            alpha.push_back(pp);
            double sum = 0.0;
            for (int po = l0; po <= r0; po++) {
              int hh = max(0, h1 - po);
              sum += dp[h0][hh][t2];
            }
            sum /= r0 - l0 + 1;
            sum *= 1.0 - pp;
            assert(!isnan(sum));
            beta.push_back(sum);
          } else {
            double pp = (double)p1 / 100;
            alpha.push_back(pp);
            double sum = 0.0;
            for (int po = l1; po <= r1; po++) {
              int hh = max(0, h0 - po);
              sum += dp[hh][h1][t2];
            }
            sum /= r1 - l1 + 1;
            sum *= 1.0 - pp;
            beta.push_back(sum);
          }
        }
        double prod = 1.0;
        for (int t = 0; t < (int)(D); ++t) prod *= alpha[t];
        if (prod > EPS) {
          double a = 1.0, b = 0.0;
          for (int t = 0; t < (int)(D); ++t) {
            b += beta[t] * a;
            a *= alpha[t];
          }
          double x = b / (1.0 - a);
          for (int t = 0; t < (int)(D); ++t) {
            dp[h0][h1][t] = x;
            x = (x - beta[t]) / alpha[t];
          }
        } else {
          memset(vis, false, sizeof(vis));
          for (int t = 0; t < (int)(D); ++t) dp[h0][h1][t] = calc(h0, h1, t);
        }
      }
    }
  }
  cout << dp[hp0][hp1][0] << "\n";
  return 0;
}
