#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9;
int main() {
  int n;
  while (cin >> n) {
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<int> lft(n);
    int best = 1;
    for (int i = 0; i < n; i++) {
      best = min(best, x[i]);
      lft[i] = best;
      best++;
    }
    vector<int> rgt(n);
    best = 1;
    for (int i = n - 1; i >= 0; i--) {
      best = min(best, x[i]);
      rgt[i] = best;
      best++;
    }
    int R = 0;
    for (int i = 0; i < n; i++) R = max(R, min(rgt[i], lft[i]));
    cout << R << "\n";
  }
  return 0;
}
