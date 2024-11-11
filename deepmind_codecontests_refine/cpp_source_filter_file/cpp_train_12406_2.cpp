#include <bits/stdc++.h>
using namespace std;
char str[13030];
char res[10][19999];
queue<int> Q;
int num[11];
int cost[11][11];
int sum[11];
int Abs(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  int i, j, u, d;
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", str);
  memset(num, 0, sizeof(num));
  for (i = 0; i < n; i++) {
    num[str[i] - '0']++;
  }
  int lesk;
  int ans = 0xfffffff;
  memset(cost, 0, sizeof(cost));
  memset(sum, 0, sizeof(sum));
  memset(res, 0, sizeof(res));
  for (i = 0; i < 10; i++) {
    lesk = k;
    u = d = i;
    lesk -= num[i];
    while (lesk > 0) {
      if (u >= 0 && u < 9) {
        u++;
      } else {
        u = 10;
      }
      if (d > 0 && d < 10) {
        d--;
      } else {
        d = 10;
      }
      if (lesk < num[u] + num[d]) {
        if (u != 10) {
          sum[i] += lesk * (u - i);
          cost[i][u - i] = lesk;
          lesk = 0;
          break;
        }
        if (d != 10) {
          sum[i] += lesk * (i - d);
          cost[i][i - d] = lesk;
          lesk = 0;
          break;
        }
      } else {
        if (u != 10) {
          sum[i] += (num[d] + num[u]) * (u - i);
          cost[i][u - i] = num[d] + num[u];
          lesk -= cost[i][u - i];
          continue;
        }
        if (d != 10) {
          sum[i] += (num[d] + num[u]) * (i - d);
          cost[i][i - d] = num[d] + num[u];
          lesk -= cost[i][i - d];
          continue;
        }
      }
    }
  }
  ans = sum[0];
  for (i = 1; i < 10; i++)
    if (sum[i] < ans) ans = sum[i];
  cout << ans << endl;
  for (i = 0; i < 10; i++) {
    if (sum[i] == ans) {
      Q.push(i);
    }
  }
  int len = 0;
  while (!Q.empty()) {
    int t = Q.front();
    Q.pop();
    for (i = 0; i < n; i++) {
      if (cost[t][Abs(t - str[i] + '0')] > 0) {
        if (str[i] - '0' > k) {
          cost[t][Abs(t - str[i] + '0')]--;
          res[len][i] = '0' + t;
        } else {
          res[len][i] = str[i];
        }
      } else {
        res[len][i] = str[i];
      }
    }
    for (i = n - 1; i >= 0; i--) {
      if (cost[t][Abs(t - res[len][i] + '0')] > 0) {
        cost[t][Abs(t - res[len][i] + '0')]--;
        res[len][i] = '0' + t;
      }
    }
    len++;
  }
  int ret = 0;
  for (i = 1; i < len; i++) {
    if (strcmp(res[ret], res[i]) > 0) ret = i;
  }
  for (i = 0; i < n; i++) cout << res[ret][i];
  cout << endl;
  return 0;
}
