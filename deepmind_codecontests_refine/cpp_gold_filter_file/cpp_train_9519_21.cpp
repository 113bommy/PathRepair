#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  int people = (n * m) - k;
  int o1 = ceil((1.0 * people) / n) * c;
  int o2 = (people)*d;
  int o3 = (c * (people / n)) + ((people % n) * d);
  cout << max(0, min(o1, min(o2, o3)));
}
