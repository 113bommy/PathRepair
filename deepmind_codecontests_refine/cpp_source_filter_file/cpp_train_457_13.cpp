#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l;
  cin >> n >> l;
  int num = 0;
  int a[n + 10];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int maxn = -114514;
  for (int i = l; i <= 100; i++) {
    num = 0;
    for (int j = 0; j < n; j++) {
      num += a[j] / i;
    }
    maxn = max(maxn, num);
  }
  cout << maxn;
  return 0;
}
