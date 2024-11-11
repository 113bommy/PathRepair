#include <bits/stdc++.h>
using namespace std;
static int a[3];
int ans[1000];
int main() {
  int m;
  cin >> m;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    a[0] = a[1] = a[2] = 0;
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      long long x;
      cin >> x;
      x = x % 3;
      a[x]++;
    }
    sum += a[0];
    sum += min(a[1], a[2]);
    sum += (a[1] - min(a[1], a[2])) / 3;
    sum += ((a[2] - min(a[1], a[2])) / 3);
    ans[i] = sum;
    sum = 0;
  }
  for (int i = 0; i < m; i++) printf("%d ", ans[i]);
  return 0;
}
