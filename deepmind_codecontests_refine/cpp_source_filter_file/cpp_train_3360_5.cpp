#include <bits/stdc++.h>
using namespace std;
int help(int* arr, int n, int x) {
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) return 1;
    sum += arr[i];
  }
  if (sum / n == x || sum % n == 0) return 1;
  return 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    int arr[n];
    m[x] = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      m[arr[i]]++;
    }
    if (m[x] == n)
      cout << 0 << endl;
    else
      cout << help(arr, n, x) << endl;
  }
  return 0;
}
