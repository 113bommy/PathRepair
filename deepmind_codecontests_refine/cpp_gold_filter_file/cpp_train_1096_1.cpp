#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int max = INT_MIN, maxi = -1, min = INT_MAX, mini = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] < min) {
      min = a[i];
      mini = i;
    }
    if (a[i] > max) {
      max = a[i];
      maxi = i;
    }
  }
  if (maxi < mini) {
    int temp = maxi;
    maxi = mini;
    mini = temp;
  }
  if (maxi > n - 1 - mini) {
    cout << maxi << endl;
  } else {
    cout << n - 1 - mini << endl;
  }
  return 0;
}
