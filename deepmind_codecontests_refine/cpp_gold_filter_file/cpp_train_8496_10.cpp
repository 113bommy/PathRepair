#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, s, d, t;
  cin >> n;
  cin >> s >> d;
  t = s;
  for (i = 2; i <= n; i++) {
    cin >> s >> d;
    k = s;
    while (k <= t) {
      k = k + d;
    }
    t = k;
  }
  cout << t << endl;
}
