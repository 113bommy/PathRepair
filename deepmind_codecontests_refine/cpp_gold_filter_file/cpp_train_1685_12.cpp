#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long int minv = arr[n - 1], count = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > minv) count++;
      minv = min(arr[i], minv);
    }
    cout << count << endl;
  }
}
