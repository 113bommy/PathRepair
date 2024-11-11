#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-15;
int n;
int answer;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    answer += (y2 - y1 + 1) * (x2 - y1 + 1);
  }
  cout << answer << endl;
  return 0;
}
