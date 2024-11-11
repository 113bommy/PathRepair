#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    int a, b, c;
    int m;
    cin >> a >> b >> c;
    if (c < a)
      arr[i] = c;
    else {
      m = b / c;
      arr[i] = (m + 1) * c;
    }
  }
  for (int i = 0; i < n; i++) cout << arr[i];
  return 0;
}
