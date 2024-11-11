#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int N = 1009;
const int sqrN = 450;
const int MOD = 1000000007;
const int INF = 1e9;
const long long INF64 = 1e18;
const long double PI = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int a[N][N];
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(n); ++j) a[i][j] = (i + j) % n;
  for (int i = 0; i < (int)(n - 1); ++i) a[n - 1][i] = a[i][n - 1] = a[i][i];
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(n); ++j)
      if (i == j)
        a[i][j] = 0;
      else if (a[i][j] == 0)
        a[i][j] = n - 1;
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(n); ++j) cout << a[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
