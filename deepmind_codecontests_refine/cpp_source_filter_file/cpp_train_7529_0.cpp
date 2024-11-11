#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int mid = (n - 1) / 2;
  int i = 0;
  int j = n;
  int t = n;
  int sum = 0;
  while (t > 0) {
    for (int k = 0; k < n; k++) {
      cin >> arr[k];
    }
    sum += arr[i];
    i++;
    sum += arr[j];
    j--;
    sum += arr[mid];
    if (t == mid) {
      for (int g = 0; g < n; g++) {
        sum += arr[g];
      }
      sum -= 3 * arr[mid];
    }
    t--;
  }
  cout << sum << "\n";
}
