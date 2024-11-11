#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int sol = 0;
  while (N--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    sol += abs(x2 - x1) * abs(y2 - y1);
  }
  cout << sol << '\n';
  return 0;
}
