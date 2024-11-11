#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 3;
const long long OO = 1e18;
long long SolveOne(long long n, long long s, long long v) {
  if (v == 1) {
    return n;
  }
  if (v == -1) {
    return 0;
  }
}
int Sign(long long a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
long long Floor(long long a, long long b) {
  if (b < 0) {
    a *= -1;
    b *= -1;
  }
  int s = Sign(a);
  a *= s;
  if (s > 0) {
    return a / b;
  } else {
    return -((a + b - 1) / b);
  }
}
long long Ceil(long long a, long long b) {
  if (b < 0) {
    a *= -1;
    b *= -1;
  }
  int s = Sign(a);
  a *= s;
  if (s > 0) {
    return (a + b - 1) / b;
  } else {
    return -(a / b);
  }
}
void Solve(long long k, long long b, bool less, long long& l, long long& r) {
  if (!less) {
    Solve(-k, -b, true, l, r);
    return;
  }
  if (k == 0) {
    if (b == 0) {
    } else {
      r = -OO;
      l = OO;
    }
    return;
  }
  if (k > 0) {
    r = min(r, Floor(b, k));
  } else {
    l = max(l, Ceil(b, k));
  }
}
long long egcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}
bool SolveDiaph(long long A, long long B, long long C, long long& x0,
                long long& y0, long long& g) {
  g = egcd(abs(A), abs(B), x0, y0);
  if (C % g != 0) return false;
  x0 *= C / g;
  y0 *= C / g;
  if (A < 0) x0 *= -1;
  if (B < 0) y0 *= -1;
  return true;
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  long long n, m;
  long long sx, sy;
  long long vx, vy;
  cin >> n >> m;
  cin >> sx >> sy;
  cin >> vx >> vy;
  if (vx == 0) {
    if (sx == 0 || sx == n) {
      long long ans = SolveOne(m, sy, vy);
      cout << sx << " " << ans << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  if (vy == 0) {
    if (sy == 0 || sy == m) {
      long long ans = SolveOne(n, sx, vx);
      cout << ans << " " << sy << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  long long A = n * vy;
  long long B = -m * vx;
  long long C = sx * vy - sy * vx;
  long long g, a0, b0;
  bool can = SolveDiaph(A, B, C, a0, b0, g);
  if (!can) {
    cout << -1 << endl;
    return 0;
  }
  long long l = -OO;
  long long r = OO;
  if (vx < 0) {
    Solve(B / g, -a0, true, l, r);
  } else {
    Solve(B / g, -a0, false, l, r);
  }
  if (l > r) {
    cout << -1 << endl;
    return 0;
  }
  long long pick = abs(l) < abs(r) ? l : r;
  long long af = a0 + pick * B / g;
  long long bf = b0 - pick * A / g;
  long long ansx = 0, ansy = 0;
  if (af % 2 == 0) {
    ansx = 0;
  } else {
    ansx = n;
  }
  if (bf % 2 == 0) {
    ansy = 0;
  } else {
    ansy = m;
  }
  cout << ansx << " " << ansy << endl;
  return 0;
}
