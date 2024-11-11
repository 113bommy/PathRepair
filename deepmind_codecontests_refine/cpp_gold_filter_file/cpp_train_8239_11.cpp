#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int n, tot, add;
int a[MAX], rec[MAX];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], tot += a[i];
  rec[++rec[0]] = 1;
  add += a[1];
  for (int i = 2; i <= n; ++i)
    if (a[1] >= 2 * a[i]) rec[++rec[0]] = i, add += a[i];
  if (add * 2 > tot) {
    printf("%d\n", rec[0]);
    for (int i = 1; i <= rec[0]; ++i) cout << rec[i] << " ";
  } else
    cout << 0 << endl;
  return 0;
}
