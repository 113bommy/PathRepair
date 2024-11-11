#include <bits/stdc++.h>
using namespace std;
int V[5001], N, ans;
int main() {
  int i, x;
  cin >> N;
  for (i = 1; i <= N; ++i) {
    cin >> x;
    if (V[x] || x > N) {
      ++ans;
    } else {
      ++V[x];
    }
  }
  cout << ans << '\n';
  return 0;
}
