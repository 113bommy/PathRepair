#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int b[maxn];
int c[maxn];
int n, m, k;
int main() {
  int T;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    c[b[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      k = a[i] + b[j];
      if (c[k] == 0) {
        cout << a[i] << " " << b[j];
        return 0;
      }
    }
  }
}
