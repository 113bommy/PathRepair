#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a, b, aa = 5, bb = 5;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i += 1) {
    cin >> a >> b;
    aa = min(aa, a);
    aa = min(aa, n - a);
    bb = min(bb, b);
    bb = min(bb, m - b);
  }
  if (aa < 5 || bb < 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
