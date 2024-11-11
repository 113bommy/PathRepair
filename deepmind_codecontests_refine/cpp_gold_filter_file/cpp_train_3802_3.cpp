#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
void build(int Now, int l, int r) {
  if (l == r) return;
  int Mid = (l + r) >> 1;
  build(Now << 1, l, Mid);
  build(Now << 1 | 1, Mid + 1, r);
}
int n, a, x[300010], y[300010], Ans = 0;
int main() {
  build(1, 1, 1000);
  scanf("%d", &n);
  int head = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    mp[a]++;
    if (mp[a] >= 2) Ans++, x[Ans] = head, y[Ans] = i, mp.clear(), head = i + 1;
  }
  if (Ans == 0)
    printf("-1");
  else {
    cout << Ans << endl;
    for (int i = 1; i <= Ans - 1; i++) cout << x[i] << ' ' << y[i] << endl;
    cout << x[Ans] << ' ' << n << endl;
  }
  return 0;
}
