#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int num = n / 2;
  sort(arr, arr + n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i < num) {
      sum += max(0, arr[i] - s);
    } else if (i == num) {
      sum += abs(arr[i] - s);
    } else if (i > num) {
      sum += max(0, s - arr[i]);
    }
  }
  cout << sum;
}
