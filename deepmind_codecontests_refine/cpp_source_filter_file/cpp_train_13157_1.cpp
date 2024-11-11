#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y, z;
  pt() {}
  pt(int a, int b, int c) : x(a), y(b), z(c) {}
  inline pt operator+(const pt& o) const {
    return pt(x + o.x, y + o.y, z + o.z);
  }
  inline pt operator-(const pt& o) const {
    return pt(x - o.x, y - o.y, z - o.z);
  }
  inline pt operator*(const int& o) const { return pt(x * o, y * o, z * o); }
};
inline long long dp(const pt& a, const pt& b) {
  return (long long)a.x * b.x + (long long)a.y * b.y + (long long)a.z * b.z;
}
const int NMAX = 32300;
int n, m;
pt a, b, amb;
int amt[NMAX];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  pt dir(1, 1, 1);
  a = pt(-1, 0, 1);
  b = pt(-1, 1, 0);
  amb = a - b;
  for (int i = m + 1; i <= n / 2 + 1; ++i) {
    long long ans = 0;
    pt pi = b * (n + 1) + amb * i;
    int j = n - m;
    int k = m + 1;
    pt pj = a * j;
    pt pk = b * k;
    pt pji = pj - pi;
    pt pki = pk - pi;
    long long cur = dp(pj - pi, pk - pi);
    for (; j >= m + 1;) {
      while (cur >= 0 && k <= n - m) {
        cur += -pji.x + pji.y;
        pki = pki + b;
        k++;
      }
      if (k == (n - m + 1)) break;
      ans += (n - m + 1) - k;
      j--;
      pji = pji - a;
      cur += -pki.x + pki.z;
    }
    amt[i] = ans;
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int v = min(i, n + 1 - i);
    ans += amt[v];
  }
  cout << ans * 3 << endl;
  return 0;
}
