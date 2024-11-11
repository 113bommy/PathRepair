#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int deg[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 2 * n; i += 2) {
    if (m < 0) {
      deg[i] = i;
      deg[i + 1] = i + 1;
    } else {
      deg[i] = i + 1;
      deg[i + 1] = i;
    }
    m--;
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (i > 1) cout << " ";
    cout << deg[i];
  }
  return 0;
}
