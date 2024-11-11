#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30);
const long long infll = (1LL << 60);
const int MAXN = 100010;
char zzz[MAXN];
string scan() {
  scanf("%s", &zzz);
  return string(zzz);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<string> ar(n);
  for (int i = 0; i < n; i++) ar[i] = scan();
  int ans = 6;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int d = 0;
      for (int k = 0; k < 6; k++) d += ar[i][k] != ar[j][k];
      int x = 0;
      for (; x < 6; x++) {
        if ((x + 1) * 2 >= d) break;
      }
      ans = min(ans, x);
    }
  }
  printf("%d\n", max(ans, 0));
}
