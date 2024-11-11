#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string tostr(const T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
const double EPS = 1e-6;
const int INF = 1000 * 1000 * 1000;
const char CINF = 102;
const long long LINF = INF * 1ll * INF;
const double PI = 3.1415926535897932384626433832795;
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
unsigned int gcd(unsigned int a, unsigned int b) {
  return a ? gcd(b % a, a) : b;
}
int n, m;
const int B = 50;
struct image {
  bool a[1700][1700];
};
struct comps {
  int a[1700][1700];
};
void filter(const image &src, image &dst, int W, bool grow) {
  if (grow) {
    memset(dst.a, 0, sizeof(dst.a));
    for (int i = 0; i < (n); ++i) {
      for (int j = 0; j < (m); ++j) {
        if (!src.a[i][j]) continue;
        for (int di = -W; di <= W; ++di) {
          int ii = i + di;
          int t = (int)sqrt((double)(W * W - di * di));
          for (int dj = -t; dj <= t; ++dj) {
            int jj = j + dj;
            dst.a[ii + B][jj + B] = true;
          }
        }
      }
    }
    for (int i = 0; i < (n); ++i) {
      for (int j = 0; j < (m); ++j) {
        dst.a[i][j] = dst.a[i + B][j + B];
      }
    }
  } else {
    for (int i = 0; i < (n); ++i) {
      for (int j = 0; j < (m); ++j) {
        bool b = true;
        for (int di = -W; di <= W; ++di) {
          int ii = i + di;
          int t = (int)sqrt((double)(W * W - di * di));
          for (int dj = -t; dj <= t; ++dj) {
            int jj = j + dj;
            bool v = src.a[ii][jj];
            b &= v;
            if (!b) break;
          }
          if (!b) break;
        }
        dst.a[i][j] = b;
      }
    }
  }
}
void subtract(const image &a, const image &b, image &dst) {
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      dst.a[i][j] = a.a[i][j] && !b.a[i][j];
    }
  }
}
void fill(image &a, comps &c, int x, int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m || !a.a[i][j]) return;
  a.a[i][j] = false;
  c.a[i][j] = x;
  fill(a, c, x, i, j - 1);
  fill(a, c, x, i, j + 1);
  fill(a, c, x, i - 1, j);
  fill(a, c, x, i + 1, j);
}
int getcomps(image &a, comps &c) {
  int k = 0;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      if (!a.a[i][j]) continue;
      fill(a, c, ++k, i, j);
    }
  }
  return k;
}
void save(const image &a, string file) {
  ofstream f(file.c_str());
  f << "P2\n" << m << ' ' << n << " 1\n";
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      f << a.a[i][j] << '\n';
    }
  }
}
int main() {
  static image src, tmp;
  cin >> n >> m;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      int a;
      scanf("%d", &a);
      src.a[i][j] = !!a;
    }
  }
  tmp = src;
  filter(tmp, src, 1, false);
  static image core, big, rays;
  filter(src, core, 2, false);
  filter(core, big, 7, true);
  subtract(src, big, rays);
  static comps sunid, rayid;
  int k = getcomps(src, sunid);
  getcomps(rays, rayid);
  vector<set<int> > res(k);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      int r = rayid.a[i][j];
      int s = sunid.a[i][j] - 1;
      if (s != -1 && r != 0) {
        res[s].insert(r);
      }
    }
  }
  vector<int> ans(k);
  for (int i = 0; i < (k); ++i) {
    ans[i] = ((int)(res[i]).size());
  }
  sort((ans).begin(), (ans).end());
  cout << k << '\n';
  for (int i = 0; i < (k); ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
