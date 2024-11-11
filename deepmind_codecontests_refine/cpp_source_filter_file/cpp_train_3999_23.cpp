#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, curr, prev, groups = 0, ten = 10, one = 01;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> curr;
    if (curr != ten && prev != ten) {
      groups++;
    }
    if (curr != one && prev != one) {
      groups++;
    }
    prev = curr;
  }
  if (n != 1)
    cout << groups - 1 << "\n";
  else
    cout << 1 << "\n";
  return 0;
}
