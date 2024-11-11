#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string first_color;
  cin >> n;
  cout << "0 1" << endl;
  cin >> first_color;
  string color;
  int low = 1, high = (int)1e9;
  for (int i = 1; i < n; i++) {
    int x = (low + high) >> 1;
    cout << x << ' ' << 1 << endl;
    cin >> color;
    if (color[0] == first_color[0]) {
      low = x + 1;
    } else {
      high = x - 1;
    }
  }
  cout << low << " 0 " << high << " 2 " << endl;
  return 0;
}
