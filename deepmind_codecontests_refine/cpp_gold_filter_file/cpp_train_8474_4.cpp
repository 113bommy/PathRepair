#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 100010;
const int M = 1e9 + 0.5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int pi = cos(-1.0);
const long long oo = 0x3f3f3f3f3f3f3f3fll;
int a, n;
char s[N];
map<int, int> h;
int sum[N];
int main() {
  scanf("%d%s", &a, s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i] - '0';
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      h[sum[j] - sum[i - 1]]++;
    }
  long long ret = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      int t = sum[j] - sum[i - 1];
      if (t == 0) {
        if (a) continue;
        ret += (n + 1ll) * n / 2;
        continue;
      }
      if (a % t) continue;
      ret += h[a / t];
    }
  cout << ret << endl;
  return 0;
}
