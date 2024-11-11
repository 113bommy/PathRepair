#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cout << ((arr[n - 1] - arr[0]) + 1) - n << "\n";
}
