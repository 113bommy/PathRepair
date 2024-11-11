#include <bits/stdc++.h>
using namespace std;
const char nxtl = (char)'\n';
const int maxn = (int)2e5 + 5;
const int INF_INT = (int)1e9 + 99;
const long long INF_BIG = (long long)1e18 + 99;
const int Mod = (int)1e9 + 7;
unsigned long long n, a[maxn], pref[maxn], de4[150];
unsigned long long id = 1;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }
  unsigned long long res = 0;
  int r = 1;
  for (;;) {
    res += pref[r];
    r = r * 4;
    if (r > n) break;
  }
  cout << res;
  return 0;
}
