#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long double EPS = 1e-7;
const long double PI = acos(-1);
const int K = 262144;
char a[N];
int main() {
  int n, l, d, ans;
  long long m = 0;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < n / 2; i++)
    m += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
  cout << m << endl;
}
