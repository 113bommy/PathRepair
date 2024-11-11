#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  long long L, R, bit;
  for (int i = 0; i < N; i++) {
    cin >> L >> R;
    for (bit = 1; L + bit <= R; bit *= 2) {
      if (!(bit & L)) L += bit;
    }
    cout << L << endl;
  }
  return;
}
int main() {
  solve();
  return 0;
}
