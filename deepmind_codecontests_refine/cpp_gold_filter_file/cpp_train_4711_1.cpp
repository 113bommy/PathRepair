#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n], counter = 1000;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
      counter = min(counter, abs(arr[i] - arr[i - 1]));
    cout << counter << endl;
  }
}
