#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long tot_time = b;
    if (tot_time < a) {
      if (d >= c) {
        cout << -1 << endl;
        continue;
      } else {
        tot_time += c * (ceil((double)(a - b) / (c - d)));
      }
    }
    cout << tot_time << endl;
  }
  return 0;
}
