#include <bits/stdc++.h>
using namespace std;
struct uu {
  int x;
  int y;
  int z;
};
int n, k, k1, k2, sum, sum1, a[100000], b[100000];
uu c[100000];
bool cmp(uu a, uu b) { return a.x < b.x; }
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (((a[i] - b[i])) <= 0) {
      k1++;
      sum += a[i];
    } else if ((a[i] - b[i]) > 0) {
      c[k2].x = a[i] - b[i];
      c[k2].y = b[i];
      c[k2].z = a[i];
      k2++;
      sum1 += b[i];
    }
  }
  if (k1 == n)
    cout << sum;
  else if (k1 < n && k1 >= k)
    cout << sum + sum1;
  else if (k1 < k) {
    sort(c, c + k2, cmp);
    for (int i = 0; i < k2 && (k1 < k); i++) {
      sum += c[i].z;
      sum1 -= c[i].y;
      k1++;
    }
    cout << sum + sum1;
  }
  return 0;
}
