#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;
const double pi = 3.1415926535897932384626433832795;
typedef long long matrix[SIZE][SIZE];
char ch[1 << 20];
string gs() {
  scanf("%s", ch);
  return string(ch);
}
string gl() {
  gets(ch);
  return string(ch);
}
template <class T>
T gcd(T a, T b) {
  return (!a) ? b : gcd(b % a, a);
}
void error() {
  int yyy = 0;
  cout << 7 / yyy;
}
int N;
int A[6];
int Mn[6][6];
int Mx[6][6];
int C[6][6];
int go(int x, int h) {
  if (x == N - 1) return 0;
  if (h >= N) {
    if (A[x] != 0) return -1 << 20;
    return go(x + 1, x + 2);
  }
  int res = -1 << 20;
  for (int p = (Mn[x][h]), _b(min(Mx[x][h], min(A[x], 5)) + 1); p < _b; ++p) {
    A[h] += p;
    A[x] -= p;
    res = max(res, p * p + (p > 0 ? C[x][h] : 0) + go(x, h + 1));
    A[h] -= p;
    A[x] += p;
  }
  return res;
}
int main() {
  scanf("%d", &N);
  for (int i = (0), _b(N * (N - 1) / 2); i < _b; ++i) {
    int a, b, l, r, c;
    scanf("%d%d%d%d%d", &a, &b, &l, &r, &c);
    --a, --b;
    Mn[a][b] = l;
    Mx[a][b] = r;
    C[a][b] = c;
  }
  int val = -1;
  int best = -1;
  for (int k = (1), _b(25 + 1); k < _b; ++k) {
    memset(A, 0, sizeof(A));
    A[0] = k;
    int v = go(0, 1);
    if (v > 0 && best == -1) {
      best = v;
      val = k;
      break;
    }
  }
  printf("%d %d\n", val, best);
  return 0;
}
