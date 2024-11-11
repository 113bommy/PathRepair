#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  int n;
  cin >> n;
  int a[200005] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sum = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] >= a[i + 1] && a[i + 1] >= 1) {
      a[i] = a[i + 1] - 1;
      sum += a[i];
    } else if (a[i + 1] == 0)
      break;
    else
      sum += a[i];
  }
  cout << sum;
}
