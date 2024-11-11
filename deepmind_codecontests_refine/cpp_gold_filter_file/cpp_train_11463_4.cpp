#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b, i, n, x;
  vector<long long> ans1, ans2;
  cin >> a >> b;
  for (x = 1; x <= 100000; x++)
    if (x * (x + 1) > 2 * (a + b)) break;
  x--;
  for (; x >= 1; x--) {
    if (x <= a) {
      ans1.push_back(x);
      a -= x;
    } else {
      ans2.push_back(x);
      b -= x;
    }
  }
  cout << ans1.size() << endl;
  for (i = 0; i < ans1.size(); i++) cout << ans1[i] << " ";
  cout << endl;
  cout << ans2.size() << endl;
  for (i = 0; i < ans2.size(); i++) cout << ans2[i] << " ";
}
