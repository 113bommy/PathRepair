#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k = 1;
  cin >> k;
  int index = 0;
  int cur_num = 1;
  int arr[k];
  while (index < k) {
    if (cur_num % 3 == 0 || cur_num % 10 == 3) {
      cur_num++;
    } else {
      arr[index] = cur_num;
      cur_num++;
      index++;
    }
  }
  cout << arr[k - 1] << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
