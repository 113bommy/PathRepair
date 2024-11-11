#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long int* arr = new long int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool pos = true;
    if (arr[0] < 0) pos = false;
    long int prevmax = arr[0];
    long int maxsum = 0;
    for (int i = 1; i < n; i++) {
      if ((arr[i] > 0 && !pos) || (arr[i] < 0 && pos)) {
        maxsum += prevmax;
        prevmax = arr[i];
        pos = !pos;
        continue;
      }
      prevmax = max(prevmax, arr[i]);
    }
    cout << maxsum + prevmax << endl;
  }
}
