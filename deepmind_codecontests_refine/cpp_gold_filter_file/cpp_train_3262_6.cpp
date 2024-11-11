#include <bits/stdc++.h>
using namespace std;
int my_own() {
  double a, b, i, x, sum = 0, count = 0;
  cin >> a >> b;
  vector<float> g, f;
  for (int i = 0; i < a; i++) {
    cin >> x;
    g.push_back(x);
    sum += x;
  }
  sum += b;
  sum = sum / a;
  for (int i = 0; i < a; i++) {
    f.push_back(sum - ((float)g[i]));
  }
  for (int i = 0; i < a; i++)
    if (f[i] < 0) {
      cout << -1;
      count = 1;
      return 0;
    }
  if (count == 0) {
    for (int i = 0; i < a; i++)
      cout << fixed << setprecision(6) << f[i] << endl;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) my_own();
  return 0;
}
