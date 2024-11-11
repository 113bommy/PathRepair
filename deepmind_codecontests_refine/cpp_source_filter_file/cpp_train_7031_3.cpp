#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int main() {
  int mi = INF, a, b;
  for (int i = 0; i < (int)4; ++i) {
    int p;
    cin >> p;
    if (p < mi) mi = p;
  }
  cin >> a >> b;
  cout << min(b - a, max(0, mi - a)) << endl;
}
