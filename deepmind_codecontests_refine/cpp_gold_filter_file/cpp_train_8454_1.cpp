#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a;
    int zero = 0;
    int sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (!arr[i]) {
        zero++;
        arr[i] = 1;
      }
    }
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum)
      cout << zero << endl;
    else
      cout << zero + 1 << endl;
  }
}
