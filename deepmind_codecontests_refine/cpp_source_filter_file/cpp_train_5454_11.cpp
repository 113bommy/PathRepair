#include <bits/stdc++.h>
using namespace std;
typedef const int& ci;
typedef const unsigned int& cui;
typedef const long long& cll;
typedef const unsigned long long& cull;
int gcd(int x, int y) { return x == 0 or y == 0 ? y + x : gcd(y, x % y); }
vector<vector<long long> > answers;
int main() {
  int n, m, x, y, a, b;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &x);
  scanf("%d", &y);
  scanf("%d", &a);
  scanf("%d", &b);
  int l = gcd(a, b);
  a /= l, b /= l;
  long long dx = a * min(m / b, n / a), dy = b * min(m / b, n / a);
  assert(dx <= n and dy <= m and dx and dy);
  long long p, q;
  for (int i = -1; i <= 2; i++) {
    if (i == -1) p = 0;
    if (i == 2) p = n - dx;
    if (i == 0 or i == 1) p = x - (dx / 2) - i;
    for (int j = -1; j <= 2; j++) {
      if (j == -1) q = 0;
      if (j == 2) q = m - dy;
      if (j == 0 or j == 1) q = y - (dy / 2) - j;
      if (q < 0 or p < 0 or p + dx > n or p + dx > m) {
        continue;
      }
      long long delta = abs(2 * x - (2 * (long long)p + dx)) +
                        abs(2 * y - (2 * (long long)q + dy));
      vector<long long> X;
      X.resize(5);
      X[0] = delta, X[1] = p, X[2] = q, X[3] = p + dx, X[4] = q + dy;
      answers.push_back(X);
    }
  }
  sort(answers.begin(), answers.end());
  printf("%d %d %d %d", (int)answers[0][1], (int)answers[0][2],
         (int)answers[0][3], (int)answers[0][4]);
}
