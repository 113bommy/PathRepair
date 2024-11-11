#include <bits/stdc++.h>
using namespace std;
double n, a, b, x, y;
set<double> s;
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if ((a - x) != 0) {
      s.insert((b - y) / (a - x));
    } else
      s.insert(10001);
  }
  cout << s.size();
  return 0;
}
