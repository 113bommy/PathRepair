#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << n + 1 << endl;
  for (int i = n - 1; i >= 0; i--) {
    int diff = (i - (arr[i] % n) + n) % n;
    for (int j = 0; j <= i; j++) arr[j] += diff;
    cout << 1 << " " << i + 1 << " " << diff << endl;
  }
  cout << 2 << " " << n << " " << n;
  return 0;
}
