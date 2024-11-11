#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
int next[N];
char s[5005];
int b[5005];
int ans;
int n, a;
int main() {
  char z[5] = "bear";
  int diss = 0;
  cin >> s;
  n = strlen(s);
  if (n % 2 != 0) {
    printf("-1\n");
  } else {
    int L = 0, U = 0, R = 0, D = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L')
        L++;
      else if (s[i] == 'U')
        U++;
      else if (s[i] == 'R')
        R++;
      else if (s[i] == 'D')
        D++;
    }
    int x, y;
    x = abs(L - R);
    y = abs(U - D);
    ans = max(x, y);
    cout << ans << endl;
  }
  return 0;
}
