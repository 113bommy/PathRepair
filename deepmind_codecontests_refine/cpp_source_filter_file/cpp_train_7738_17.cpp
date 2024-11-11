#include <bits/stdc++.h>
using namespace std;
bool Pr[1005], flag;
int main() {
  int n, k;
  cin >> n >> k;
  memset(Pr, 1, sizeof(Pr));
  Pr[1] = 0;
  for (int i = 2; i <= n; i++)
    if (Pr[i])
      for (int j = 2; j * i <= n; j++) Pr[i * j] = 0;
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    flag = 0;
    if (!Pr[i]) continue;
    for (int j = 2; j < i; j++) {
      if (Pr[j])
        for (int k = 1; j + k <= n; k++)
          if (Pr[j + k]) {
            if (2 * j + k == i) {
              cnt++;
              flag = 1;
            }
            break;
          }
      if (flag) break;
    }
  }
  if (cnt >= k)
    puts("YES");
  else
    puts("NO");
  return 0;
}
