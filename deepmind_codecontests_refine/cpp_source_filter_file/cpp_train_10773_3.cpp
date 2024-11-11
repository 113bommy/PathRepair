#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
int A[5005], B[5005];
vector<int> M;
long long x, y;
void calc(int l, int r) {
  x = 0, y = A[l];
  for (int i = (l); i < (r); i++) {
    if (B[i] == 1) {
      x += y;
      y = A[i + 1];
    } else {
      y *= A[i + 1];
    }
  }
}
int main() {
  string s;
  cin >> s;
  s = "1*" + s;
  s = s + "*1";
  int l = s.size();
  for (int i = 0; i < l; i += 2) A[i / 2] = s[i] - '0';
  for (int i = 1; i < l; i += 2) {
    if (s[i] == '+')
      B[i / 2] = 1;
    else {
      B[i / 2] = 2;
      M.push_back(i / 2);
    }
  }
  long long Ans = 0;
  for (int i = (0); i < (M.size()); i++) {
    for (int j = (i + 1); j < (M.size()); j++) {
      calc(0, M[i]);
      long long X = x, Y = y;
      calc(M[i] + 1, M[j]);
      Y = Y * (x + y);
      long long temp = A[M[j]];
      A[M[j]] = Y;
      calc(M[j], s.size() / 2);
      A[M[j]] = temp;
      Ans = max(Ans, X + x + y);
    }
  }
  cout << Ans << "\n";
  return 0;
}
