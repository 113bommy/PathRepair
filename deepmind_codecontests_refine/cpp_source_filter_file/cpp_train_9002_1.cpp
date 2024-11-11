#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x1, y1, x2, y2;
  int result;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    result += (x2 - x1 + 1) * (y2 - y1 + 1);
  }
  cout << result << endl;
}
