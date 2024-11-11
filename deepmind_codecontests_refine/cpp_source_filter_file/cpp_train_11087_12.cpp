#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[100001];
  int v[100001];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int mx = arr[n - 1];
  v[0] = 0;
  int c = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (mx > arr[i]) {
      v[c] = mx - arr[i] + 1;
      c++;
    } else {
      mx = arr[i];
      v[c] = 0;
      c++;
    }
  }
  for (int i = c - 1; i >= 0; i--) {
    cout << v[i];
    if (i > 0) cout << " ";
  }
  return 0;
}
