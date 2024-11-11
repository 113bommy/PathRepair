#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[10000];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  int maxx = 0;
  for (int i = 1; i <= m; i++) {
    int left, right;
    cin >> left >> right;
    int sum = 0;
    sum += (a[right] - a[left - 1]);
    if (sum > 0) {
      maxx += sum;
    }
  }
  cout << maxx;
  return 0;
}
