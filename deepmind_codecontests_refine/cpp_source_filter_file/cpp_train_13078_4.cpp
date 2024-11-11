#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ma = 1000;
  cin >> n;
  int arr[n];
  int s = 0;
  int g = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    s = 0;
    if (i == n - 1) break;
    for (int j = i; j < n + i; j++) {
      s += arr[j % n];
      g = 360 - s;
      ma = min(ma, abs(g - s));
    }
  }
  cout << ma << endl;
}
