#include <bits/stdc++.h>
using namespace std;
const int N = 111;
long long dp[N], nextM[N], use;
char a[N], c[N];
int b, d, lena, lenc, ans, tmp;
void cnt(int i) {
  dp[i] = 0, nextM[i] = 0, use = 0;
  while (use < lena) {
    if (a[use] == c[nextM[i]]) {
      nextM[i]++;
      if (nextM[i] == lenc) dp[i]++, nextM[i] = 0;
    }
    use++;
  }
}
int main() {
  cin >> b >> d >> a >> c;
  lena = strlen(a);
  lenc = strlen(c);
  for (int i = 0; i < lena; i++) cnt(i);
  for (int i = 0; i < b; i++) {
    ans += dp[tmp];
    tmp = nextM[tmp];
  }
  cout << ans / d << endl;
  return 0;
}
