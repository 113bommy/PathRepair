#include <bits/stdc++.h>
using namespace std;
int arr[1000000], a[1000000], b[1000000];
int main() {
  int n, ans = 0, x, y, andis = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < andis; i++)
    for (int j = 0; j < andis; j++)
      if (a[i] == b[j] && i != j) {
        ans++;
        break;
      }
  cout << n - ans << endl;
  return 0;
}
