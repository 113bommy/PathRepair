#include <bits/stdc++.h>
const double Pi = 3.14159265;
const double eps = 1e-10;
const double pi = acos(-1);
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const unsigned long long base = 163;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
string s1 = "sjfnb", s2 = "cslnb";
int n;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  if (a[n] == 0 || (a[2] == 0 && n > 1)) return cout << s2, 0;
  int l = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i + 1]) l++;
    if (a[i] == a[i + 1] && a[i - 1] == a[i] - 1 && i > 1) return cout << s2, 0;
  }
  if (l > 1) return cout << s2, 0;
  long long now = 0;
  for (int i = 1; i <= n; ++i) {
    now += a[i] - (i - 1);
  }
  if (now & 1)
    cout << s1;
  else
    cout << s2;
  return 0;
}
