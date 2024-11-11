#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int curr = 0;
  int energy = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] >= curr) {
      if (v[i] - curr > energy) {
        ans = ans + v[i] - curr - energy;
        energy = 0;
      } else {
        energy = energy - v[i] + curr;
      }
    } else {
      energy = energy + curr - v[i];
    }
    curr = v[i];
  }
  cout << ans << endl;
}
