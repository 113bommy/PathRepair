#include <bits/stdc++.h>
using namespace std;
long long int powr(int s, int p) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    long long int q = powr(s, p / 2);
    long long int a = q;
    q = (a * a);
    q = (q * s);
    return (q);
  } else {
    long long int q = powr(s, p / 2);
    long long int a = q;
    q = (a * a);
    return (q);
  }
}
int main() {
  int a[100010];
  int n, m;
  int q = 9999999;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    q = min(x, q);
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  int i = 0;
  long long int ret = 0;
  while (i != n) {
    if (n - i > q) {
      for (int j = i; j < i + q; j++) ret += a[j];
      i = i + q;
      if (n - i >= 2) {
        i = i + 2;
      } else if (n - i == 1) {
        i++;
      }
    } else
      for (; i < n; i++) ret += a[i];
  }
  cout << ret << endl;
  return 0;
}
