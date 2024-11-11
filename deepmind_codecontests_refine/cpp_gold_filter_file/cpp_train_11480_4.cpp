#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long steps = 0, j = 0;
    for (int i = 1; i < n; i++) {
      while (i < n && arr[j] >= arr[i]) {
        steps += (arr[i - 1] > arr[i]) ? abs(arr[i - 1] - arr[i]) : 0;
        i++;
      }
      j = i;
    }
    cout << steps << endl;
  }
}
