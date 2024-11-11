#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
}
int main() {
  io();
  int n, m;
  cin >> n >> m;
  vector<int> a(110);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    ++a[--x];
  }
  for (int ans = 100; ans >= 1; --ans) {
    vector<int> copy = a;
    int people = 0;
    for (int i = 0; i < 110; ++i) {
      people += copy[i] / ans;
    }
    if (people >= n) {
      cout << ans;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
