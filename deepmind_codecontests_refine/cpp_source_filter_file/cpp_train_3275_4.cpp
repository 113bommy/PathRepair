#include <bits/stdc++.h>
using namespace std;
int main() {
  int nums[] = {1, 2, 3, 5};
  int n, k;
  cin >> n >> k;
  cout << k * n * 6 - 1 << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cout << k * (6 * i + nums[j]) << " ";
    }
    cout << endl;
  }
  return 0;
}
