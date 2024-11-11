#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v, v + n);
  int aux = 1, ans = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i] >= aux) {
      ans++;
      aux++;
    }
  }
  cout << ans << endl;
}
