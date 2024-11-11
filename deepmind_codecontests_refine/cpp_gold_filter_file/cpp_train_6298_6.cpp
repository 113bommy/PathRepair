#include <bits/stdc++.h>
using namespace std;
const int QUERY = 100;
const int SIZE = 100001;
int query[QUERY];
int a[SIZE], b[SIZE], c[SIZE];
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &query[i]);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      if (a[i] <= query[j] && b[i] >= query[j]) {
        ans += (query[j] - a[i]) + c[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
