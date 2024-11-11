#include <bits/stdc++.h>
using namespace std;
long long a[8][3];
inline long long sqr(long long a) { return a * a; }
inline long long sm(long u, long v1, long v2) {
  return (a[v1][0] - a[u][0]) * (a[v2][0] - a[u][0]) +
         (a[v1][1] - a[u][1]) * (a[v2][1] - a[u][1]) +
         (a[v1][2] - a[u][2]) * (a[v2][2] - a[u][2]);
}
bool check() {
  long long b[8];
  long c[8];
  for (long i = 0; i < 8; i++) {
    for (long j = 0; j < 8; j++)
      b[j] = sqr(a[i][0] - a[j][0]) + sqr(a[i][1] - a[j][1]) +
             sqr(a[i][2] - a[j][2]);
    long long l = 1e18L;
    for (long j = 0; j < 8; j++)
      if (b[j] && b[j] < l) l = b[j];
    long cnt = 0;
    for (long j = 0; j < 8; j++)
      if (b[j] == l) c[cnt++] = j;
    if (cnt != 3) return false;
    if (sm(i, c[0], c[1]) || sm(i, c[1], c[2]) || sm(i, c[2], c[0]))
      return false;
  }
  return true;
}
bool work(long n = 1) {
  for (long i = 0; i < 6; i++) {
    bool r;
    if (n < 7)
      r = work(n + 1);
    else
      r = check();
    if (r) return true;
    next_permutation(&a[n][0], &a[n][0] + 3);
  }
  return false;
}
int main() {
  for (long i = 0; i < 8; i++)
    for (long j = 0; j < 3; j++) cin >> a[i][j];
  if (work()) {
    cout << "YES\n";
    for (long i = 0; i < 8; i++) {
      for (long j = 0; j < 3; j++) cout << a[i][j] << ' ';
      cout << endl;
    }
  } else
    cout << "NO";
  return 0;
}
