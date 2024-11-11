#include <bits/stdc++.h>
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;
int st[100001];
int main() {
  int n, o = 0, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    while (o && a > st[o]) {
      ans = max(ans, a | st[o]);
      o--;
    }
    if (o) ans = max(ans, a | st[o]);
    st[++o] = a;
  }
  cout << ans << endl;
  return 0;
}
