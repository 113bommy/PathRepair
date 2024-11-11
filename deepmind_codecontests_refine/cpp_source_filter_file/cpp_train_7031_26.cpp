#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[4], a, b;
  for (int i = 0; i < 4; i++) {
    cin >> arr[i];
  }
  cin >> a >> b;
  int y = *min_element(arr, arr + 4) - 1;
  int x = min(y, b);
  if (x == 0) {
    cout << 0 << endl;
  } else {
    cout << (x - a + 1) << endl;
  }
  return 0;
}
