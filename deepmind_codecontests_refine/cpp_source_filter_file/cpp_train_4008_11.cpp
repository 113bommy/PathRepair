#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  float b;
  cin >> a >> b;
  float v[2 * a];
  for (int x = 0; x < 2 * a; x++) {
    cin >> v[x];
  }
  sort(v, v + 2 * a);
  if (2 * v[0] < v[a]) {
    float r = 6 * a * v[0];
    cout << fixed << setprecision(9) << min(b, r);
  } else {
    float r = (v[a] / 2) * a + v[a] * a;
    cout << fixed << setprecision(9) << min(b, r);
  }
}
