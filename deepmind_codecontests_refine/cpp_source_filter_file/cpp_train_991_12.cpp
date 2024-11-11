#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  num += 2;
  vector<int> tv(num);
  tv[0] = 0, tv[num - 1] = 115;
  int ans = 90;
  for (int a = 1; a < num; a++) {
    cin >> tv[a];
    if (tv[a] - tv[a - 1] > 15) {
      ans = tv[a - 1] + 15;
      break;
    }
  }
  cout << ans;
}
