#include <bits/stdc++.h>
using namespace std;
template <class T>
T Mul(T x, T y, T P) {
  T F1 = 0;
  while (y) {
    if (y & 1) {
      F1 += x;
      if (F1 < 0 || F1 >= P) F1 -= P;
    }
    x <<= 1;
    if (x < 0 || x >= P) x -= P;
    y >>= 1;
  }
  return F1;
}
template <class T>
T Pow(T x, T y, T P) {
  T F1 = 1;
  x %= P;
  while (y) {
    if (y & 1) {
      F1 = Mul(F1, x, P);
    }
    x = Mul(x, x, P);
    y >>= 1;
  }
  return F1;
}
template <class T>
T Gcd(T x, T y) {
  if (y == 0) return x;
  T z;
  while (z = x % y) {
    x = y, y = z;
  }
  return y;
}
template <class T>
void UpdateMin(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdateMax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <class T>
T Sqr(const T x) {
  return x * x;
}
template <class T>
T Abs(const T x) {
  return x < 0 ? -x : x;
}
class ReadBuffer {
 private:
  char buff[20000000];
  char *buf;

 public:
  void init(int size = 20000000) {
    fread(buff, 1, size, stdin);
    buf = buff;
  }
  template <class T>
  bool readInteger(T &x) {
    x = 0;
    while (*buf && isspace(*buf)) ++buf;
    if (*buf == 0) return false;
    static bool flag;
    flag = 0;
    if (*buf == '-')
      flag = true;
    else
      x = *buf - '0';
    while (isdigit(*++buf)) x = x * 10 + *buf - '0';
    if (flag) x = -x;
    return true;
  }
  template <class T>
  bool readFloat(T &x) {
    long double nowpos = 0.1;
    x = 0;
    while (*buf && isspace(*buf)) ++buf;
    if (*buf == 0) return false;
    static bool flag, decimal;
    decimal = flag = 0;
    if (*buf == '-')
      flag = true, ++buf;
    else if (*buf == '.')
      decimal = true;
    while (isdigit(*buf) || *buf == '.') {
      if (*buf == '.')
        decimal = true;
      else {
        if (decimal) {
          x += nowpos * (*buf - '0');
          nowpos *= 0.1;
        } else {
          x = x * 10 + *buf - '0';
        }
      }
      ++buf;
    }
    return true;
  }
  bool readChar(char c) {
    if (*buf == 0) return 0;
    return c = *buf++, 1;
  }
  bool readString(char *s) {
    while (*buf && isspace(*buf)) ++buf;
    if (!*buf) return false;
    while (!isspace(*buf)) *s++ = *buf++;
    *s++ = 0;
    return true;
  }
  int countSpacetonext() {
    int total = 0;
    while (*buf && *buf == ' ') ++total, ++buf;
    return total;
  }
  bool splitBycharactor(char *s, char Split = '\n') {
    while (*buf && *buf != Split) *s++ = *buf++;
    *s++ = 0;
    return *buf != 0;
  }
};
struct EDGE {
  int T;
  EDGE *Nxt;
};
struct Query {
  int bound, id, L, R;
  Query(int bound, int id, int L, int R) : bound(bound), id(id), L(L), R(R) {}
};
int N, M, K, Q;
vector<Query> V[100001], H[100001];
bool ans[200001];
vector<int> IV[100001], IH[100001];
int lt[262180];
void insert(int x, int y) {
  x += 131072;
  lt[x] = y;
  while (x >>= 1) {
    lt[x] = max(lt[x << 1], lt[(x << 1) | 1]);
  }
}
int query(int l, int r) {
  int ret = 0;
  l += 131071;
  r += 131073;
  while (l ^ r ^ 1) {
    if (~l & 1) ret = max(ret, lt[l ^ 1]);
    if (r & 1) ret = max(ret, lt[r ^ 1]);
    l >>= 1, r >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d%d%d", &N, &M, &K, &Q);
  for (int i = 1; i <= (K); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    IH[x].push_back(y);
    IV[y].push_back(x);
  }
  for (int i = 1; i <= (Q); ++i) {
    ans[i] = false;
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    H[a].push_back(Query(c, i, b, d));
    V[b].push_back(Query(d, i, a, c));
  }
  for (int i = 1; i <= (N); ++i) insert(i, M + 1);
  for (int i = (N); 0 < i; --i) {
    for (int j = 0; j < int(IH[i].size()); ++j) insert(IH[i][j], i);
    for (int j = 0; j < int(H[i].size()); ++j) {
      if (query(H[i][j].L, H[i][j].R) <= H[i][j].bound) {
        ans[H[i][j].id] = true;
      }
    }
  }
  for (int i = 1; i <= (M); ++i) insert(i, N + 1);
  for (int i = (M); 0 < i; --i) {
    for (int j = 0; j < int(IV[i].size()); ++j) insert(IV[i][j], i);
    for (int j = 0; j < int(V[i].size()); ++j) {
      if (query(V[i][j].L, V[i][j].R) <= V[i][j].bound) {
        ans[V[i][j].id] = true;
      }
    }
  }
  for (int i = 1; i <= (Q); ++i) {
    printf("%s\n", ans[i] ? "YES" : "NO");
  }
  return 0;
}
