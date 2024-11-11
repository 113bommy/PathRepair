#include <bits/stdc++.h>
using namespace std;
string p[101000], q[101000];
long long int cost[101000], ans[101000][2];
int i, j, n, m;
char buffer[101000];
void fix(long long int& a, long long int b) {
  if (b < 0) return;
  if (a < 0 || a > b) a = b;
}
int main() {
  scanf("%d", &n);
  memset(ans, -1, sizeof(ans));
  int temp;
  for (i = 0; i < (int)n; ++i) {
    scanf("%d", &temp);
    cost[i] = temp;
  }
  for (i = 0; i < (int)n; ++i) {
    scanf("%s", buffer);
    p[i] = buffer;
    q[i] = p[i];
    std::reverse(q[i].begin(), q[i].end());
  }
  ans[n - 1][0] = 0;
  ans[n - 1][1] = cost[n - 1];
  for (i = n - 2; i >= 0; i--) {
    if (p[i] <= p[i + 1] && ans[i + 1][0] >= 0) {
      fix(ans[i][0], ans[i + 1][0]);
      ans[i][0] = ans[i + 1][0];
    }
    if (p[i] <= q[i + 1] && ans[i + 1][1] >= 0) {
      fix(ans[i][0], ans[i + 1][1]);
    }
    if (q[i] <= p[i + 1] && ans[i + 1][0] >= 0) {
      fix(ans[i][1], ans[i + 1][0] + cost[i]);
    }
    if (p[i] <= q[i + 1] && ans[i + 1][1] >= 0) {
      fix(ans[i][1], ans[i + 1][1] + cost[i]);
    }
  }
  long long int a = -1;
  fix(a, ans[0][0]);
  fix(a, ans[0][1]);
  printf("%I64\n", a);
  return 0;
}
