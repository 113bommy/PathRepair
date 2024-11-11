#include <bits/stdc++.h>
using namespace std;
unsigned long long sum = 0;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long test = 2;
  int arr_size = n;
  for (int i = 0; i < arr_size - 1; i++) {
    sum += (test * arr[i]);
    test++;
  }
  sum += (test - 1) * arr[n - 1];
  cout << sum << endl;
  return 0;
}
