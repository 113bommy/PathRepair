#include <bits/stdc++.h>
using namespace std;
int arr[120000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  k += 2000;
  arr[0] = -1;
  for (int i = 1; i < 2000; ++i) {
    if (k > 1e6)
      arr[i] = 1e6, k -= 1e6;
    else
      arr[i] = k, k = 0;
  }
  cout << 2000 << endl;
  for (int i = 0; i < 2000; ++i) {
    cout << arr[i] << " ";
  }
}
