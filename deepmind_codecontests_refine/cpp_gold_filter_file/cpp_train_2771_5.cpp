#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 100;
int n;
int x[2010], cnt[MAXN], y[2010];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]), cnt[x[i]]++;
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]), cnt[y[i]]++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((x[i] ^ y[j]) > (int)2e6)
        continue;
      else if (cnt[x[i] ^ y[j]])
        ++ans;
    }
  }
  if (ans % 2)
    puts("Koyomi");
  else
    puts("Karen");
  return 0;
}
