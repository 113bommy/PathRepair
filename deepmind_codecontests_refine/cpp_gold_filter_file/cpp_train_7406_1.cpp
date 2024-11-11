#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  int ans = 0;
  if (vec[0] == 1 && vec[n - 1] == 1) {
    ans = 2;
  }
  int temp = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (vec[i % n] == 0) {
      temp = 0;
    } else {
      temp++;
    }
    if (temp > ans) {
      ans = temp;
    }
  }
  cout << ans << endl;
  return 0;
}
