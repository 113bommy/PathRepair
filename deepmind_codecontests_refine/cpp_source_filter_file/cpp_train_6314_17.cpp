#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    long long pos;
    cin >> pos;
    if (pos % 2 != 0) {
      cout << (pos + 1) / 2 << endl;
      continue;
    }
    long long step = (2 * n - 1 - pos) / 2 + 1;
    while (step % 2 == 0) {
      step /= 2;
    }
    int sol = (step + 1) / 2;
    sol = n - sol + 1;
    cout << sol << endl;
  }
  return 0;
}
