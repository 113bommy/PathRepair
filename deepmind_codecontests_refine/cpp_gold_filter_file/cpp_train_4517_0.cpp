#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n, k, v = 0, num = 0;
  cin >> n >> k;
  if (n - 1 == k)
    for (int i = n; i >= 1; i--) cout << i << " ";
  else {
    if (k == 0) {
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
      return 0;
    }
    int i;
    for (i = n - 1; i >= 1; i--) {
      num++;
      cout << i << " ";
      if (num == k) {
        cout << n << " ";
        break;
      }
    }
    for (int j = 1; j < i; j++) cout << j << " ";
  }
  cout << endl;
  return 0;
}
