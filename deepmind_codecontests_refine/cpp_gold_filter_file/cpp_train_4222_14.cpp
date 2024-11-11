#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-8;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 1000100;
int n;
int a[MAXN];
pair<int, int> t[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    int x;
    scanf("%d", &x);
    t[x - 1].first = i;
  }
  for (int i = 0; i < (int)(n); i++) {
    int x;
    scanf("%d", &x);
    t[x - 1].second = i;
  }
  for (int i = 0; i < (int)(n); i++) a[t[i].first] = t[i].second;
  reverse(a, a + n);
  vector<int> d(n + 1, INF);
  d[0] = -INF;
  for (int i = 0; i < (int)(n); i++) {
    int j = (int)(upper_bound(d.begin(), d.end(), a[i]) - d.begin() - 1);
    if (d[j] < a[i] && a[i] < d[j + 1]) d[j + 1] = a[i];
  }
  int ans = 0;
  for (int i = 0; i < (int)(d.size()); i++)
    if (abs(d[i]) != INF) ans++;
  cout << ans << endl;
  return 0;
}
