#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int d, v, h, e;
  cin >> d >> h >> v >> e;
  float hdec = (4 * v * 1.00) / (3.141593 * d * d);
  if ((hdec - e) > 1e-4) {
    cout << "YES\n";
    float t = (h * 1.00) / (hdec - e);
    cout << fixed << setprecision(4) << t << "\n";
  } else
    cout << "NO\n";
}
