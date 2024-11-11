#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> V(n);
  for (int i = 0; i < (int)n; ++i) cin >> V[i];
  sort(V.begin(), V.end());
  int ans = 0;
  int c = 1;
  for (int i = 0; i < (int)n; ++i) {
    if (V[i] > c + 1) {
      V[i] = c + 1;
      c++;
    } else if (V[i] > c) {
      c = V[i];
    }
  }
  cout << c + 1 << "\n";
  return 0;
}
