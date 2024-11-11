#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int n, m;
int a[maxn], b[maxn];
int sum = 0;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int tempa = a[0], i = 0, j = 0, tempb = b[0];
  while (i < n && j < m) {
    if (tempa < tempb) {
      i++;
      tempa += a[i];
    } else if (tempa > tempb) {
      j++;
      tempb += b[j];
    } else {
      i++;
      j++;
      tempa = a[i];
      tempb = b[j];
      sum++;
    }
  }
  cout << sum;
  return 0;
}
