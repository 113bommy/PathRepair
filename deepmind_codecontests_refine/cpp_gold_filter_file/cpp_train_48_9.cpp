#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxp = 31623;
bool isprimes[maxp + 1];
vector<int> primes;
int n;
vector<pair<int, long long> > fa[100], fb[100];
pair<int, int> x[100];
struct Point {
  long long x, y;
  Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};
long long powmod(long long a, long long k) {
  long long ret = 1;
  while (k) {
    if (k & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    k >>= 1;
  }
  return ret;
}
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= x * (a / b);
  return d;
}
long long find(const vector<pair<int, long long> >& f, int p) {
  int pos = lower_bound(f.begin(), f.end(), make_pair(p, -1ll)) - f.begin();
  if (pos != f.size() && f[pos].first == p) {
    return f[pos].second;
  }
  return 0;
}
vector<pair<int, long long> > factor(int x) {
  vector<pair<int, long long> > ret;
  for (int i = 0; i < primes.size() && x > 1; ++i) {
    long long cnt = 0;
    while (x % primes[i] == 0) {
      cnt++;
      x /= primes[i];
    }
    if (cnt) {
      ret.push_back(make_pair(primes[i], cnt));
    }
  }
  if (x > 1) {
    ret.push_back(make_pair(x, 1));
  }
  return ret;
}
int main() {
  memset(isprimes, true, sizeof isprimes);
  for (int i = 2; i <= maxp; ++i) {
    if (isprimes[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= maxp; j += i) {
        isprimes[j] = false;
      }
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i].first, &x[i].second);
  }
  sort(x, x + n);
  n = unique(x, x + n) - x;
  for (int i = 0; i < n; ++i) {
    fa[i] = factor(x[i].first);
    fb[i] = factor(x[i].second);
  }
  bool flag = true;
  int pos = n;
  for (int k = pos - 1; k >= 1 && flag; k = pos - 1) {
    pos = 0;
    for (int i = 0; i < k && flag; ++i) {
      vector<int> v;
      for (int j = 0; j < fa[i].size(); ++j) {
        if (fa[i][j].second) {
          v.push_back(fa[i][j].first);
        }
      }
      for (int j = 0; j < fa[i + 1].size(); ++j) {
        if (fa[i + 1][j].second) {
          v.push_back(fa[i + 1][j].first);
        }
      }
      for (int j = 0; j < fb[i].size(); ++j) {
        if (fb[i][j].second) {
          v.push_back(fb[i][j].first);
        }
      }
      for (int j = 0; j < fb[i + 1].size(); ++j) {
        if (fb[i + 1][j].second) {
          v.push_back(fb[i + 1][j].first);
        }
      }
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      Point p(-1, -1);
      Point s(-1, -1);
      Point must(-1, -1);
      for (int j = 0; j < v.size(); ++j) {
        long long a1 = find(fa[i], v[j]);
        long long a2 = find(fa[i + 1], v[j]);
        long long b1 = find(fb[i], v[j]);
        long long b2 = find(fb[i + 1], v[j]);
        long long x, y, dx, dy;
        long long d = exgcd(b1, -b2, x, y);
        if (b1 == 0 && b2 == 0) {
          if (a1 != a2) {
            flag = false;
            break;
          }
          continue;
        } else if (b1 == 0) {
          if (a1 >= a2 && (a1 - a2) % b2 == 0) {
            y = (a1 - a2) / b2;
            if (must.y != -1 && must.y != y) {
              flag = false;
              break;
            }
            must.y = y;
          } else {
            flag = false;
            break;
          }
        } else if (b2 == 0) {
          if (a2 >= a1 && (a2 - a1) % b1 == 0) {
            x = (a2 - a1) / b1;
            if (must.x != -1 && must.x != x) {
              flag = false;
              break;
            }
            must.x = x;
          } else {
            flag = false;
            break;
          }
        } else if ((a2 - a1) % d == 0) {
          x *= (a2 - a1) / d;
          y *= (a2 - a1) / d;
          dx = b2 / abs(d);
          dy = b1 / abs(d);
          if (x > 0) {
            if (dx != 0) {
              long long t = (x - 1) / dx + 1;
              x -= t * dx;
              y -= t * dy;
            }
          }
          if (y > 0) {
            if (dy != 0) {
              long long t = (y - 1) / dy + 1;
              x -= t * dx;
              y -= t * dy;
            }
          }
          if (x < 0) {
            if (dx == 0) {
              flag = false;
              break;
            }
            long long t = (-x - 1) / dx + 1;
            x += t * dx;
            y += t * dy;
          }
          if (y < 0) {
            if (dy == 0) {
              flag = false;
              break;
            }
            long long t = (-y - 1) / dy + 1;
            x += t * dx;
            y += t * dy;
          }
          if (p.x == -1 && p.y == -1) {
            p = Point(x, y);
            s = Point(dx, dy);
          } else {
            if (s.x == 0 && s.y == 0) {
              if (p.x < x || p.y < y || (p.x - x) * dy - dx * (p.y - y) != 0) {
                flag = false;
                break;
              }
            } else {
              if (s.x == dx && s.y == dy) {
                if ((p.x - x) * dy - dx * (p.y - y) != 0) {
                  flag = false;
                  break;
                }
                if (p.x < x) {
                  p = Point(x, y);
                }
              } else {
                long long k1 = (x * dy - y * dx + dx * p.y - dy * p.x) /
                               (s.x * dy - s.y * dx);
                long long nx = p.x + s.x * k1;
                long long ny = p.y + s.y * k1;
                if (nx < x || ny < y || (nx - x) * dy - dx * (ny - y) != 0) {
                  flag = false;
                  break;
                }
                p = Point(nx, ny);
                s = Point(0, 0);
              }
            }
          }
        } else {
          flag = false;
          break;
        }
      }
      if (flag) {
        if (p.x == -1 && p.y == -1) {
          if (must.x == -1 && must.y == -1) {
            continue;
          } else if (must.x == -1) {
            p.x = 0;
            s.x = 1;
          } else {
            p.x = must.x;
            s.x = 0;
          }
        } else {
          if (must.x != -1 && must.y != -1) {
            if (s.x == 0 && s.y == 0 && (p.x != must.x || p.y != must.y)) {
              flag = false;
              break;
            }
            if (must.x < p.x || must.y < p.y ||
                (must.x - p.x) * s.y - s.x * (must.y - p.y) != 0) {
              flag = false;
              break;
            }
            p.x = must.x;
            s.x = 0;
          } else if (must.x != -1) {
            if (must.x < p.x || (s.x != 0 && (must.x - p.x) % s.x != 0) ||
                (s.x == 0 && must.x != p.x)) {
              flag = false;
              break;
            }
            p.x = must.x;
            s.x = 0;
          } else if (must.y != -1) {
            if (must.y < p.y || (s.y != 0 && (must.y - p.y) % s.y != 0) ||
                (s.y == 0 && must.y != p.y)) {
              flag = false;
              break;
            }
            if (s.y != 0) {
              long long t = (must.y - p.y) / s.y;
              p.x = p.x + t * s.x;
              s.x = 0;
            }
          }
        }
        vector<pair<int, long long> > nfa;
        vector<pair<int, long long> > nfb;
        for (int j = 0; j < v.size(); ++j) {
          long long a1 = find(fa[i], v[j]);
          long long b1 = find(fb[i], v[j]);
          if (b1 * p.x + a1) {
            nfa.push_back(make_pair(v[j], b1 * p.x + a1));
          }
          if (b1 * s.x) {
            nfb.push_back(make_pair(v[j], b1 * s.x));
          }
        }
        fa[pos] = nfa;
        fb[pos++] = nfb;
      }
    }
  }
  if (flag) {
    long long ans = 1;
    for (int i = 0; i < fa[0].size(); ++i) {
      ans = ans * powmod(fa[0][i].first, fa[0][i].second) % mod;
    }
    printf("%I64d\n", ans);
  } else {
    printf("-1\n");
  }
  return 0;
}
