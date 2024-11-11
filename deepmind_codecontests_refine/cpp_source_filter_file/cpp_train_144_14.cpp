#include <bits/stdc++.h>
using namespace std;
int main() {
  int days, c;
  int max, pos;
  int diff;
  cin >> days >> c;
  int arr[days];
  for (int i = 0; i < days; i++) cin >> arr[i];
  max = 0;
  for (int i = 0; i < days - 1; i++) {
    diff = arr[i] - arr[i + 1];
    if (max < diff) {
      max = diff;
    }
  }
  if (max == 0)
    cout << 0;
  else {
    cout << max - c;
  }
  return 0;
}
