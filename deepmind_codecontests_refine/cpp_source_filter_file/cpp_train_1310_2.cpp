#include <bits/stdc++.h>
using namespace std;
int n;
int x[1000005];
int father[1000005];
int getfather(int x1) {
  return x1 == father[x1] ? x1 : father[x1] = getfather(father[x1]);
}
void merge(int a, int b) {
  int _a = getfather(a);
  int _b = getfather(b);
  father[_b] = father[_a];
}
bool dian[1000005];
int main() {
  int m, n;
  cin >> n >> m;
  long long huan = 0;
  int a, b;
  for (int i = 1; i <= n; i++) father[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    dian[a] = dian[b] = true;
    if (a != b) {
      x[a]++;
      x[b]++;
    } else
      huan++;
    merge(a, b);
  }
  int t = -1;
  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (t == -1 && dian[i])
      t = getfather(i);
    else if (dian[i] && t != getfather(i))
      flag = false;
  if (!flag) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  long long tmp = 0;
  for (int i = 1; i <= m; i++) {
    ans += 1LL * x[i] * (x[i] - 1) / 2;
    tmp += 1LL * x[i] * huan;
  }
  ans += tmp / 2;
  ans += 1LL * huan * (huan - 1) / 2;
  cout << ans << endl;
}
