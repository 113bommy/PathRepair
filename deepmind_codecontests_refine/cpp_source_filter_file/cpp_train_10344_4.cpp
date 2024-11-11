#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    a[temp] = i;
  }
  int m;
  cin >> m;
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= m; i++) {
    int temp;
    cin >> temp;
    sum1 += a[temp];
    sum2 += n - a[temp] + 1;
  }
  cout << sum1 << " " << sum2;
}
