#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  long long arr[2001];
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, greater<int>());
  cout << arr[a - 1] - arr[b - 1] << endl;
}
