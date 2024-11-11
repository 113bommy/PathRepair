#include <bits/stdc++.h>
using namespace std;
int prime[10000000], que[10000000], vis[10000000];
int main() {
  long long i, j, n, cnt = 0, tmp, flag = 0, besti = -1;
  long long ans;
  memset(prime, 0, sizeof(prime));
  memset(vis, 0, sizeof(vis));
  for (i = 2; i * i < 10000000; i++)
    if (prime[i] == 0) {
      for (j = i * 2; j < 10000000; j += i) prime[j] = 1;
    }
  for (i = 2; i < 10000000; i++)
    if (prime[i] == 0) que[cnt++] = i;
  cin >> n;
  tmp = n;
  if (n < 10000000 - 2 && prime[n] == 0) {
    printf("1\n0\n");
    return 0;
  }
  for (i = 0; i < cnt; i++) {
    while (tmp >= que[i] && tmp % que[i] == 0) {
      vis[que[i]]++;
      tmp /= que[i];
      flag++;
      besti = que[i];
    }
  }
  if (tmp == n) {
    cout << "1" << endl;
    cout << "0" << endl;
    return 0;
  }
  if (tmp != 1 && flag != 0) {
    printf("1\n");
    cout << tmp * besti << endl;
    return 0;
  }
  if (flag >= 3) {
    printf("1\n");
    ans = 1, flag = 0;
    for (i = 0; i * i <= n && flag < 2; i++)
      while (flag < 2 && vis[i]) {
        ans *= i, flag++;
        vis[i]--;
      }
    cout << ans << endl;
  } else
    printf("2\n");
  return 0;
}
