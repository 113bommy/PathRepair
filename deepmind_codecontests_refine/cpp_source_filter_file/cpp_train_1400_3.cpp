#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const long long modulo = 1000000007;
struct point {
  long long x, y;
};
point operator-(point A, point B) {
  point C;
  C.x = A.x - B.x;
  C.y = A.y = B.y;
  return C;
}
bool operator==(point A, point B) { return (A.x == B.x && A.y == B.y); }
long long cross(point A, point B) { return (A.x * B.y - A.y * B.x); }
long long dot(point A, point B) { return A.x * B.x + A.y * B.y; }
struct Line {
  long long A, B, C;
  Line(point P, point R) {
    A = R.y - P.y;
    B = P.x - R.x;
    C = (P.y * R.x) - (P.x * R.y);
  }
};
long long sgn(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  if (x == 0) return 0;
}
long long f(Line L, point P) { return sgn(L.A * P.x + L.B * P.y + L.C); }
bool OnSegment(point A, point B, point X) {
  if (f(Line(A, B), X) != 0) return false;
  if (dot(A - X, B - X) < 0)
    return true;
  else
    return false;
}
bool intersect(point A, point B, point C, point D) {
  if (A == C || A == D || B == C || B == D) return false;
  if (f(Line(A, B), C) * f(Line(A, B), D) > 0) return false;
  if (f(Line(C, D), A) * f(Line(C, D), B) > 0) return false;
  return true;
}
point a[MAXN];
long long dp[MAXN][MAXN];
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i].x >> a[i].y;
  }
  a[N + 1] = a[1];
  long long Area = 0;
  for (int i = 1; i <= N; i++) {
    Area += cross(a[i], a[i + 1]);
  }
  Area = abs(Area);
  for (int d = 1; d < N - 1; d++) {
    for (int l = 1; l + d <= N; l++) {
      int r = l + d;
      if (d == 1) {
        dp[l][r] = 1;
        continue;
      } else
        dp[l][r] = 0;
      bool bad = false;
      for (int i = 1; i <= N; i++) {
        if (i != l && i != r && OnSegment(a[l], a[r], a[i])) bad = true;
      }
      if (bad) continue;
      for (int i = 1; i <= N; i++) {
        int next = i + 1;
        if (next == N + 1) next = 1;
        if (intersect(a[l], a[r], a[i], a[next])) bad = true;
      }
      if (bad) continue;
      long long AreaX = 0, AreaY = 0;
      for (int i = l; i <= r; i++) {
        int next = i + 1;
        if (next == r + 1) next = l;
        AreaX += cross(a[i], a[next]);
      }
      int j = 1;
      while (j <= N) {
        int next;
        if (j == l)
          next = r;
        else
          next = j + 1;
        if (next == N + 1) next = 1;
        AreaY += cross(a[j], a[next]);
        j = next;
        if (j == 1) j = N + 1;
      }
      if (Area != abs(AreaX) + abs(AreaY)) continue;
      for (int i = l + 1; i < r; i++) {
        dp[l][r] += (dp[l][i] * dp[i][r]) % modulo;
        dp[l][r] = dp[l][r] % modulo;
      }
    }
  }
  dp[1][N] = 0;
  for (int i = 2; i < N; i++) {
    dp[1][N] += (dp[1][i] * dp[i][N]) % modulo;
    dp[1][N] = dp[1][N] % modulo;
  }
  cout << dp[1][N] << endl;
  return 0;
}
