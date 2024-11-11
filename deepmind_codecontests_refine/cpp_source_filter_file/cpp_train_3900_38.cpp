#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int Max_Bit = 63;
const int INF = 2000000000;
const long long LINF = 1000000000000000007ll;
const int MOD = 1000000007;
const int NMAX = 100005;
const int MMAX = 3005;
const string CODE = "CODEFORCES";
long long d1[2 * MMAX], d2[2 * MMAX], sol[2];
pair<int, int> v[2];
static int a[MMAX][MMAX];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline void upd(const int c, const int i, const int j, const long long val) {
  if (val > sol[c]) {
    sol[c] = val;
    v[c].first = i;
    v[c].second = j;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  sol[0] = sol[1] = -1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i + 1][j + 1]);
      d1[i + j + 2] += a[i + 1][j + 1];
      d2[i - j + n] += a[i + 1][j + 1];
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      upd((i + j) & 1, i, j, d1[i + j + 2] + d2[i - j + n] - a[i + 1][j + 1]);
  printf("%d\n", sol[0] + sol[1]);
  if (v[0] > v[1]) swap(v[0], v[1]);
  cout << v[0].first + 1 << " " << v[0].second + 1 << " ";
  cout << v[1].first + 1 << " " << v[1].second + 1 << "\n";
  return 0;
}
