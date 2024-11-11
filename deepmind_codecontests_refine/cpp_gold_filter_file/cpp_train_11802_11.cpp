#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(const T& c) {
  return c.size();
}
template <class T>
inline int length(const T& c) {
  return c.length();
}
unsigned long long l, r, k, m;
vector<unsigned long long> can;
struct matrix {
  unsigned long long val[2][2];
  friend matrix operator*(const matrix a, const matrix b) {
    matrix ret;
    for (int i = (0), _b = ((2) - 1); i <= _b; i++)
      for (int j = (0), _b = ((2) - 1); j <= _b; j++) {
        ret.val[i][j] = 0;
        for (int k = (0), _b = ((2) - 1); k <= _b; k++)
          ret.val[i][j] = (ret.val[i][j] + a.val[i][k] * b.val[k][j]) % m;
      }
    return ret;
  }
  friend matrix operator^(const matrix a, const unsigned long long n) {
    if (n == 1) return a;
    matrix ret = a ^ (n / 2);
    ret = ret * ret;
    if (n % 2 == 1) ret = ret * a;
    return ret;
  }
};
unsigned long long fibo(unsigned long long n) {
  if (n <= 2)
    return 1 % m;
  else if (n == 3)
    return 2 % m;
  else {
    matrix a;
    a.val[0][0] = 0;
    a.val[0][1] = 1;
    a.val[1][0] = 1;
    a.val[1][1] = 1;
    n -= 3;
    a = a ^ n;
    return (a.val[1][0] + 2 * a.val[1][1]) % m;
  }
}
int main() {
  while (cin >> m >> l >> r >> k) {
    can.clear();
    for (unsigned long long i = 1; i * i <= r; i++) {
      (can).push_back((i));
      (can).push_back((r / i));
      if (i * i <= l)
        if (l % i == 0)
          (can).push_back((l / i));
        else
          (can).push_back((l / (i - 1)));
    }
    unsigned long long ret = 1;
    for (int i = (0), _b = ((can.size()) - 1); i <= _b; i++) {
      unsigned long long a = l / can[i];
      if (l % can[i] != 0) a++;
      unsigned long long b = r / can[i];
      if (b - a + 1 >= k) ret = max(ret, can[i]);
    }
    cout << fibo(ret) << endl;
  }
  return 0;
}
