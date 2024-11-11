#include <bits/stdc++.h>
using namespace std;
int a, b = 1, c, d;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  cout << arr[n / 2];
}
