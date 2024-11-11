#include <bits/stdc++.h>
using namespace std;
const int N = 203600;
int ia[N], ib[N], ans[N], x;
int n;
int main() {
  cin >> n;
  for (int i = (1); i <= (int)(n); i++) cin >> x, ia[x] = i;
  for (int i = (1); i <= (int)(n); i++) cin >> x, ib[x] = i;
  for (int i = (1); i <= (int)(n); i++) ans[ib[x]] = ia[x];
  for (int i = (1); i <= (int)(n); i++) cout << ans[i] << " ";
  return 0;
}
