#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long M = (long long)1e9 + 7;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long Long() {
  long long x;
  scanf("%lld", &x);
  return x;
}
void Char(char *ch) { scanf("%s", ch); }
template <typename t>
inline t abs(t a) {
  if (a >= 0) return a;
  return -a;
}
template <typename T>
inline T modpow(T b, T p, T Mod) {
  T res = 1;
  while (p) {
    if (p & 1) {
      res *= b;
      res %= Mod;
    }
    b *= b;
    b %= Mod;
    p >>= 1;
  }
  return res;
}
template <typename T>
inline T ModInv(T b, T Mod) {
  return modpow(b, Mod - 2, Mod);
}
template <typename T>
inline T pwr(T b, T p) {
  T res = 1;
  while (p) {
    if (p & 1) {
      res *= b;
    }
    b *= b;
    p >>= 1;
  }
  return res;
}
template <typename T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T, typename U>
inline void Int(T &a, U &b) {
  Int(a);
  Int(b);
}
template <typename T, typename U, typename W>
inline void Int(T &a, U &b, W &c) {
  Int(a, b);
  Int(c);
}
template <typename T, typename U, typename W, typename X>
inline void Int(T &a, U &b, W &c, X &d) {
  Int(a, b, c);
  Int(d);
}
vector<int> Unique(vector<int> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " ";
  err(++it, args...);
}
int a[N];
int main() {
  int n = Int(), f = 0;
  for (int i = 1; i <= n + 1; i++) {
    a[i] = Int();
    if (a[i] == 1) {
      f++;
    }
  }
  int first = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 1 and a[i + 1] > 1) {
      first = 1;
    }
  }
  if (first == 0) {
    printf("perfect\n");
  } else {
    printf("ambiguous\n");
    int k = 0, d = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (i == 1) {
        int s = a[i];
        while (s--) {
          printf("0 ");
        }
      } else {
        int c = a[i];
        while (c) {
          for (int j = k + 1; j <= d and c; j++, c--) {
            printf("%d ", j);
          }
        }
      }
      d += a[i];
      k += a[i - 1];
    }
    puts("");
    k = 0, d = 0;
    int g = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (i == 1) {
        int s = a[i];
        while (s--) {
          printf("0 ");
        }
      } else {
        int c = a[i];
        if (c >= 2) {
          printf("%d %d ", d, d);
          c -= 2;
          g = 2;
        }
        while (c) {
          for (int j = d; j > k and c; j--, c--) {
            printf("%d ", j);
          }
        }
      }
      g = 0;
      d += a[i];
      k += a[i - 1];
    }
  }
  return 0;
}
