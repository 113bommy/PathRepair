#include <bits/stdc++.h>
using namespace std;
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  optimizeIO();
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> v(n);
  for (int i = (int)(0); i <= (int)(n - 1); i++) cin >> v[i];
  if (x > y) {
    cout << n;
    return 0;
  }
  sort(v.begin(), v.end());
  int nos = lower_bound(v.begin(), v.end(), x) - v.begin();
  nos++;
  cout << nos / 2;
}
