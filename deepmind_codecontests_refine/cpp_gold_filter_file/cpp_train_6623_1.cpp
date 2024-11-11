#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, k;
  cin >> n >> k >> x;
  int arr[n], total = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n - k; i++) total += arr[i];
  total += k * x;
  cout << total << endl;
  return 0;
}
