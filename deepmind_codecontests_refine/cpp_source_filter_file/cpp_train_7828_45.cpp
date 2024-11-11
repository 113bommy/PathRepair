#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int arr[100] = {0};
  for (int i = 0; i < n; i++) {
    arr[a[i]]++;
  }
  for (int i = 0; i < 100; i++) {
    arr[i] = arr[i] / 2;
    sum += arr[i];
  }
  sum = sum / 2;
  cout << sum;
  return 0;
}
