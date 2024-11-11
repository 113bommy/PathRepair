#include <bits/stdc++.h>
using namespace std;
const int NM_MAX = 102;
int n, m;
void f(int lg, int v[]) {
  if (lg == 1) {
    v[1] = 1;
    return;
  }
  if (lg == 2) {
    v[1] = 3;
    v[2] = 4;
    return;
  }
  if (lg & 1) {
    for (int i = 1; i <= lg - 2; i++) v[i] = 1;
    v[lg - 1] = 2;
    v[lg] = lg / 2;
  } else {
    for (int i = 1; i <= lg - 1; i++) v[i] = 1;
    v[lg] = (lg - 1) / 2;
  }
}
int a[NM_MAX], b[NM_MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  f(n, a);
  f(m, b);
  for (int i = 1; i <= n; i++, cout << "\n")
    for (int j = 1; j <= m; j++) cout << a[i] * b[j] << " ";
  return 0;
}
