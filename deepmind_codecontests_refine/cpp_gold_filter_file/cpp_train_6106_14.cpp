#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  char lastc, c;
  for (int i = 0; i < 4; i++) cin >> lastc;
  int maxr = 1000000000, minl = -1000000000;
  for (int i = 4; i < n; i++) {
    cin >> c;
    if (c != lastc) {
      if (c == '1') {
        int max = arr[i];
        for (int j = 1; j <= 4; j++) {
          if (arr[i - j] > max) {
            max = arr[i - j];
          }
        }
        if (max >= minl) minl = max + 1;
      } else {
        int min = arr[i];
        for (int j = 1; j <= 4; j++) {
          if (arr[i - j] < min) min = arr[i - j];
        }
        if (min <= maxr) maxr = min - 1;
      }
    }
    lastc = c;
  }
  printf("%d %d\n", minl, maxr);
}
