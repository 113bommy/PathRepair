#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int numb = 0;
    long long result = 0;
    while (numb < n) {
      int max = arr[numb];
      for (numb; numb < n; numb++) {
        if (arr[numb] >= max) {
          max = arr[numb];
        } else {
          break;
        }
      }
      result += max;
      if (numb < n) {
        int min = arr[numb];
        for (numb; numb < n; numb++) {
          if (arr[numb] <= min) {
            min = arr[numb];
          } else {
            break;
          }
        }
        if (numb < n) {
          result -= min;
        }
      }
    }
    cout << result << endl;
  }
  return 0;
}
