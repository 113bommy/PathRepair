#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 1000000007;
const int to = 5;
int inv[] = {0, 1, 3, 2, 4};
int n, m, ar[N][N], where[N], hold[N];
char ch[N];
long long ans;
int add(int x, int y) {
  x += y;
  if (x >= to) x -= to;
  return x;
}
int sub(int x, int y) {
  x -= y;
  if (x < 0) x += to;
  return x;
}
int mul(int x, int y) {
  x = (x * y) % to;
  return x;
}
void gauss() {
  int base = 0;
  for (int i = 0; i < n; i++) {
    int next = -1;
    for (int j = base; j < n; j++) {
      if (ar[j][i]) {
        next = j;
        break;
      }
    }
    if (next != -1) {
      swap(ar[base], ar[next]);
      where[i] = base;
      int x = inv[ar[base][i]];
      for (int j = 0; j < m; j++) {
        ar[base][j] = mul(ar[base][j], x);
      }
      for (int j = next + 1; j < n; j++) {
        for (int z = m - 1; z >= i; z--) {
          ar[j][z] = sub(ar[j][z], mul(ar[base][z], ar[j][i]));
        }
      }
      base++;
    }
  }
  for (int i = base; i < n; i++) {
    ans = (ans * 5LL) % mod;
  }
}
int main() {
  ans = 1;
  scanf("%d%d", &n, &m);
  memset(where, -1, sizeof(where));
  for (int i = 0; i < n; i++) {
    scanf("%s", ch);
    for (int j = 0; j < m; j++) {
      ar[i][j] = ch[j] - 'a';
    }
  }
  gauss();
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%s", ch);
    for (int i = 0; i < m; i++) {
      hold[i] = ch[i] - 'a';
    }
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      if (!hold[i]) continue;
      if (where[i] == -1) {
        flag = 1;
        break;
      }
      for (int j = m - 1; j >= i; j--) {
        hold[j] = sub(hold[j], mul(ar[where[i]][j], hold[i]));
      }
    }
    if (flag)
      printf("0\n");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
