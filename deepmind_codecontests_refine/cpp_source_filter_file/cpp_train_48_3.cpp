#include <bits/stdc++.h>
const int Maxn = 100;
const int Mod = 1000000007;
const int Maxm = 6000;
int quick_power(int a, long long b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = 1ll * ans * a % Mod;
    }
    b >>= 1;
    a = 1ll * a * a % Mod;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int n;
int a[Maxn + 5], b[Maxn + 5];
struct Node {
  long long k, b;
  Node(long long _k = 0, long long _b = 0) {
    k = _k;
    b = _b;
  }
};
int p[Maxm + 5];
int len;
Node f[Maxm + 5], g[Maxm + 5];
void get_p(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      p[++len] = i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    p[++len] = x;
  }
}
struct Function {
  long long a, b, c;
  Function(long long _a = 0, long long _b = 0, long long _c = 0) {
    a = _a;
    b = _b;
    c = _c;
  }
};
bool vis;
int solve(int b, int k) {
  for (int i = 1; i <= len; i++) {
    g[i] = Node(0, 0);
  }
  for (int i = 1; i <= len; i++) {
    while (k % p[i] == 0) {
      k /= p[i];
      g[i].k++;
    }
    while (b % p[i] == 0) {
      b /= p[i];
      g[i].b++;
    }
  }
  if (!vis) {
    for (int i = 1; i <= len; i++) {
      f[i] = g[i];
    }
    vis = 1;
    return 1;
  }
  for (int t = 0; t < 3; t++) {
    for (int i = 1; i <= n; i++) {
      long long f_b = f[i].b, f_k = f[i].k, g_b = g[i].b, g_k = g[i].k;
      if (f_k == 0 && g_k == 0) {
        if (f_b != g_b) {
          return 0;
        }
      } else if (f_k == 0 || g_k == 0) {
        bool flag = 0;
        if (f_k == 0) {
          std::swap(f_k, g_k);
          std::swap(f_b, g_b);
          flag = 1;
        }
        if (g_b < f_b || (g_b - f_b) % f_k) {
          return 0;
        }
        long long k = (g_b - f_b) / f_k;
        if (flag) {
          for (int j = 1; j <= len; j++) {
            g[j].b += g[j].k * k;
            g[j].k = 0;
          }
        } else {
          for (int j = 1; j <= len; j++) {
            f[j].b += f[j].k * k;
            f[j].k = 0;
          }
        }
      }
    }
  }
  Function F;
  int flag = 0;
  long long x = -1, y = -1;
  for (int i = 1; i <= len; i++) {
    long long f_b = f[i].b, f_k = f[i].k, g_b = g[i].b, g_k = g[i].k;
    if (f_k && g_k) {
      if (!flag) {
        F = Function(f_k, -g_k, g_b - f_b);
        flag = 1;
      } else if (flag == 1) {
        long long a = f_k, b = -g_k, c = g_b - f_b;
        long long d = gcd(F.a, a);
        long long m_1 = a / d, m_2 = F.a / d;
        F.a *= m_1, F.b *= m_1, F.c *= m_1;
        a *= m_2, b *= m_2, c *= m_2;
        if (F.a == a && F.b == b) {
          if (F.c != c) {
            return 0;
          } else {
            long long d = gcd(gcd(F.a, std::abs(F.b)), std::abs(F.c));
            F.a /= d, F.b /= d, F.c /= d;
            continue;
          }
        } else {
          c -= F.c, b -= F.b;
          if (c < 0) {
            c = -c;
            b = -b;
          }
          if (b < 0 || c % b) {
            return 0;
          }
          y = c / b, x = (F.c - F.b * y) / F.a;
          if (x < 0 || (F.c - F.b * y) % F.a) {
            return 0;
          }
          flag = 2;
        }
      } else if (flag == 2) {
        long long a = f_k, b = -g_k, c = g_b - f_b;
        if (a * x + b * y != c) {
          return 0;
        }
      }
    }
  }
  if (flag == 2) {
    for (int i = 1; i <= n; i++) {
      f[i].b += f[i].k * x;
      f[i].k = 0;
    }
  }
  if (flag == 1) {
    long long x, y;
    long long d = exgcd(F.a, -F.b, x, y);
    y = -y;
    if (F.c % d) {
      return 0;
    }
    long long k_x = -F.b / d, k_y = F.a / d;
    x *= F.c / d, y *= F.c / d;
    long long t_x = 0, t_y = 0;
    if (x < 0) {
      t_x = -((-x + k_x - 1) / k_x);
    } else {
      t_x = x / k_x;
    }
    if (y < 0) {
      t_y = -((-y + k_y - 1) / k_y);
    } else {
      t_y = y / k_y;
    }
    x -= k_x * std::min(t_x, t_y);
    y -= k_y * std::min(t_x, t_y);
    for (int i = 1; i <= n; i++) {
      f[i].b += f[i].k * x;
      f[i].k *= k_x;
    }
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    get_p(a[i]);
    get_p(b[i]);
  }
  std::sort(p + 1, p + 1 + len);
  len = std::unique(p + 1, p + 1 + len) - p - 1;
  for (int i = 1; i <= n; i++) {
    if (!solve(a[i], b[i])) {
      puts("-1");
      return 0;
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = 1ll * ans * quick_power(p[i], f[i].b) % Mod;
  }
  printf("%d\n", ans);
  return 0;
}
