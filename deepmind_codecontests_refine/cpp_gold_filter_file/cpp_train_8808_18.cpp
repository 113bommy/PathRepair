#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500 + 10;
const long long val = 2333;
long long c[maxn][maxn];
int n, m, q;
int lowbit(int x) { return x & (-x); }
void add(int x, int y, long long k) {
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= m; j += lowbit(j)) c[i][j] += k;
}
void update(int x1, int y1, int x2, int y2, long long k) {
  add(x2 + 1, y2 + 1, k);
  add(x2 + 1, y1, -k);
  add(x1, y2 + 1, -k);
  add(x1, y1, k);
}
long long sum(int x, int y) {
  long long ans = 0;
  for (int i = x; i; i -= lowbit(i))
    for (int j = y; j; j -= lowbit(j)) ans += c[i][j];
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int cas = 1; cas <= q; cas++) {
    int num, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &num, &x1, &y1, &x2, &y2);
    long long ans = x1;
    ans = ans * val + y1;
    ans = ans * val + x2;
    ans = ans * val + y2;
    if (num == 1)
      update(x1, y1, x2, y2, ans);
    else if (num == 2)
      update(x1, y1, x2, y2, -ans);
    else {
      long long ans1 = sum(x1, y1);
      long long ans2 = sum(x2, y2);
      if (ans1 == ans2)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
