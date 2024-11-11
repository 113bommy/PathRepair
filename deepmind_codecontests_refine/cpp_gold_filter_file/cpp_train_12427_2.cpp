#include <bits/stdc++.h>
using namespace std;
template <class T>
T By(T x, T y, T P) {
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
T Mul(T x, T y, T P) {
  T F1 = 1;
  x %= P;
  while (y) {
    if (y & 1) {
      F1 = By(F1, x, P);
    }
    x = By(x, x, P);
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
struct EDGE {
  int T;
  EDGE *Nxt;
};
template <class T>
void UpdataMin(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdataMax(T &x, T y) {
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
struct Vector {
  long long v[101];
  int len;
  Vector operator<<(int t) {
    Vector x = *this;
    for (int i = (x.len) - 1; - 1 < i; --i) {
      x.v[i + t] = x.v[i];
    }
    x.len += t;
    for (int i = 0; i < (t); ++i) x.v[i] = 0;
    return x;
  }
  void operator+=(Vector x) {
    len = max(len, x.len);
    for (int i = 0; i < (len); ++i) {
      v[i] += x.v[i];
    }
  }
} V[80], Ans;
int main() {
  V[0].v[0] = V[0].v[1] = 1, V[0].len = 2;
  long long n, t;
  cin >> n >> t;
  long long nowlen = 2;
  int now = 0;
  if ((t ^ (t & -t)) != 0)
    cout << 0 << endl;
  else {
    int num = 0;
    while ((1LL << num) != t) ++num;
    while (n >= nowlen) {
      Ans += V[now];
      V[now + 1] = V[now] << 1;
      V[now + 1] += V[now];
      n -= nowlen;
      nowlen *= 2, ++now;
    }
    if (n == 1) {
      ++Ans.v[0];
      cout << Ans.v[num] << endl;
    } else {
      int counter = 0;
      nowlen /= 2, now--;
      while (n > 1) {
        if (n >= nowlen) {
          n -= nowlen;
          Ans += V[now] << counter;
          ++counter;
        }
        nowlen >>= 1, --now;
      }
      if (n == 1) ++Ans.v[counter];
      cout << Ans.v[num] << endl;
    }
  }
  cin >> n;
  return 0;
}
