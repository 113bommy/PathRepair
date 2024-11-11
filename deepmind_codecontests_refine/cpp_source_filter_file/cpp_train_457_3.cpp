#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int a[maxn];
int sum = 0;
int main() {
  int n, l = 0, m = 0;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = l; i <= 100; i++) {
    sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += a[j] / i;
    }
    m = max(m, sum * i);
  }
  cout << m << endl;
  return 0;
}
