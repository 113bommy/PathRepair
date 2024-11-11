#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++ans;
    if (x >= a && x < b) --ans;
  }
  cout << ans << endl;
}