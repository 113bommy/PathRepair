#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int arr[2004];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  cout << arr[b] - arr[a] << endl;
  return 0;
}
