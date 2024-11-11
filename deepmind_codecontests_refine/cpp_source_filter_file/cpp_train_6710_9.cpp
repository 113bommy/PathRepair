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
const int KMAX = 6;
const string CODE = "CODEFORCES";
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int m, ans = 0;
  char a[NMAX];
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  while (a[ans] == '1') {
    ans++;
  }
  printf("%d\n", ans + 1);
}
