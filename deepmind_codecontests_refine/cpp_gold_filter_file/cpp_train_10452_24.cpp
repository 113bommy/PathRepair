#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, p, nkn;
};
bool cmp1(node x, node y) {
  if (x.b == y.b) return x.a > y.a;
  return x.b < y.b;
}
bool cmp2(node x, node y) {
  if (x.a == y.a) return x.b > y.b;
  return x.a > y.a;
}
bool cmp3(node x, node y) {
  if (x.b == y.b) return x.a > y.a;
  return x.b > y.b;
}
node data[100010], fir[100010], sec[100010];
int ans[100010];
int n, p, k;
int main() {
  cin >> n >> p >> k;
  int tmp = p - k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &data[i].a, &data[i].b);
    data[i].p = i;
    fir[i] = data[i];
  }
  sort(fir + 1, fir + n + 1, cmp1);
  for (int i = 1; i <= n; ++i) {
    sec[i] = fir[i];
    fir[i].nkn = i;
  }
  sort(fir + tmp + 1, fir + n + 1, cmp2);
  int res = n + 1;
  int cnt = 0;
  for (int i = tmp + 1; i <= tmp + k; ++i) {
    ans[++cnt] = fir[i].p;
    res = min(res, fir[i].nkn);
  }
  res--;
  sort(sec + 1, sec + res + 1, cmp3);
  for (int i = 1; i <= tmp; ++i) ans[++cnt] = sec[i].p;
  sort(ans + 1, ans + cnt + 1, less<int>());
  for (int i = 1; i <= p; ++i) printf("%d ", ans[i]);
  cout << endl;
  return 0;
}
