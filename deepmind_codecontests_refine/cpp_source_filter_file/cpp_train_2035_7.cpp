#include <bits/stdc++.h>
using namespace std;
int n, a, b, x[100000 + 10], ans;
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    x[a]++;
    x[b]++;
  }
  for (int i = 0; i < n - 1; i++) {
    ans += (x[i] * (x[i] - 1)) / 2;
  }
  cout << ans << endl;
}
