#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
inline long long int bigmod(long long int a, long long int b, long long int m) {
  if (b == 0) return 1 % m;
  long long int x = bigmod(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) {
    x = (x * a) % m;
  }
  return x;
}
inline long long int phi(long long int n) {
  long long int ret = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
    }
    ret -= ret / i;
  }
  if (n > 1) {
    ret -= ret / n;
  }
  return ret;
}
long long int missing_number(long long int A[], long long int n) {
  long long int x1 = A[0], x2 = 1;
  for (int i = 1; i < n; i++) x1 ^= A[i];
  for (int i = 2; i <= n + 1; i++) x2 ^= i;
  return (x1 ^ x2);
}
bool isFibo(long long int n) {
  long long int A = (5 * n * n + 4);
  long long int B = (5 * n * n - 4);
  long long int C = sqrt(A);
  long long int D = sqrt(B);
  return (A == (C * C) || B == (D * D));
}
long long int classini(long long int n) { return (n & 1) ? -1 : 1; }
long long int factorial(int n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
long long int catanal(long long int n) {
  return (factorial(2 * n) / ((factorial(n + 1) * factorial(n))));
}
string orientation_3_ordered_point(vector<pair<int, int> > V) {
  long long int value =
      (V[1].second - V[0].second) * (V[2].first - V[1].first) -
      (V[1].first * V[0].first) * (V[2].second - V[1].second);
  string res;
  if (value == 0) res = "colinear";
  value == 1 ? res = "clockwise" : res = "counterclockwise";
  return res;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
string make_string(long long int num) {
  stringstream ss;
  ss << num;
  string s;
  ss >> s;
  return s;
}
long long int make_num(string s) {
  stringstream ss;
  long long int tmp;
  ss << s;
  ss >> tmp;
  return tmp;
}
int SET(int mask, int pos) { return (mask | (1 << pos)); }
int check(int mask, int pos) { return (mask & (1 << pos)); }
int A[500010];
int N, K;
int M[505050];
int main() {
  scanf("%d", &N), scanf("%d", &K);
  int ind = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  int cnt = 0;
  int L = 1, R = 1, Rh = 0, Lf = 0, ANS = -1;
  while (L <= N) {
    if (cnt < K && R <= N) {
      M[A[R]]++;
      if (M[A[R]] == 1) cnt++;
      if (ANS < (R - L + 1)) {
        ANS = R - L + 1;
        Lf = L;
        Rh = R;
      }
      R++;
    } else if (cnt == K && R <= N) {
      if (M[A[R]]) {
        if (ANS < (R - L + 1)) {
          ANS = R - L + 1;
          Lf = L;
          Rh = R;
        }
        M[A[R]]++;
        R++;
      } else {
        M[A[L]]--;
        if (M[A[L]] == 0) {
          cnt--;
        }
        L++;
      }
    } else {
      M[A[L]]--;
      if (M[A[L]] == 0) {
        cnt--;
      }
      L++;
    }
  }
  printf("%d", Lf);
  printf(" ");
  ;
  printf("%d", Rh);
  return 0;
}
