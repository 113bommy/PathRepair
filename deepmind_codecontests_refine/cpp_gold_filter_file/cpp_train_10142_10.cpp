#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int a, b;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  cin >> a >> b;
  for (int i = 0; i < 6; i++) {
    if (abs(arr[i] - a) == abs(arr[i] - b)) {
      cnt2 += 1;
    }
    if (abs(arr[i] - a) < abs(arr[i] - b)) {
      cnt1 += 1;
    }
    if (abs(arr[i] - a) > abs(arr[i] - b)) {
      cnt3 += 1;
    }
  }
  cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
  return 0;
}
