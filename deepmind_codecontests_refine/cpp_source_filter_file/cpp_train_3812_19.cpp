#include <bits/stdc++.h>
namespace FASTIO {
char buf[1 << 21];
char *p1, *p2;
template <typename T>
inline void wt(T x, char c = '\n') {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  static char sta[sizeof(T) * 8];
  T top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + '0');
  putchar(c);
}
template <typename T>
inline T rd() {
  T sum = 0, fl = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  for (; ch < '0' || ch > '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-')
      fl = -1;
    else if (ch == EOF)
      exit(0);
  for (; '0' <= ch && ch <= '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    sum = sum * 10 + ch - '0';
  return sum * fl;
}
}  // namespace FASTIO
using namespace FASTIO;
struct vec5 {
  int v[5];
  void get() {
    for (int i = 0; i < 5; i++) v[i] = rd<int>();
  }
  inline vec5 operator-(const vec5 &B) const {
    vec5 res = *this;
    for (int i = 0; i < 5; i++) res.v[i] -= B.v[i];
    return res;
  }
  inline int operator*(const vec5 &B) const {
    int ans = 0;
    for (int i = 0; i < 5; i++) ans += v[i] * B.v[i];
    return ans;
  }
  inline double abs() const { return sqrt(*this * *this); }
  inline double angle(const vec5 &B) {
    return acos((*this * B) / ((double)abs() * B.abs()));
  }
};
int n;
std::vector<vec5> V;
int main() {
  n = rd<int>();
  V.resize(n);
  for (vec5 &v : V) v.get();
  std::vector<bool> ans;
  ans.resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (j != i)
        for (int k = j + 1; k < n; k++)
          if (k != i)
            if (std::abs((V[k] - V[i]).angle(V[j] - V[i])) + 1e-6 <
                1.57079632679489661923) {
              ans[i] = true;
              j = k = n;
            }
  std::vector<int> res;
  res.reserve(n);
  for (int i = 0; i < n; i++)
    if (!ans[i]) res.push_back(i);
  wt(res.size());
  for (const int &r : res) wt(r);
  return 0;
}
