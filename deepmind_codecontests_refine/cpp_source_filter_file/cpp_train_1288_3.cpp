#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int main() {
  int i, j, k, n;
  cin >> n >> k;
  if (n < 3 * k) {
    cout << "-1" << endl;
    return 0;
  }
  for (j = 1; j <= 3 * k; j++) arr[j] = ((j - 1) >> 1) % k, arr[j]++;
  for (i = j; i <= n; i++) {
    arr[i] = i % k;
    arr[i]++;
  }
  for (i = 1; i <= n; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
