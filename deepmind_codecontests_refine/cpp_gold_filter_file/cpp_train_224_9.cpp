#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, maxl = 0, minr = 1000000000;
  cin >> N;
  long n[N];
  long long l, r;
  for (int i = 0; i < N; i++) {
    cin >> n[i];
    for (int j = 0; j < n[i]; j++) {
      cin >> l >> r;
      maxl = max(maxl, l);
      minr = min(minr, r);
    }
    if (n[i] != 1) {
      if (maxl - minr < 0) {
        cout << 0 << endl;
      } else
        cout << maxl - minr << endl;
    } else
      cout << 0 << endl;
    maxl = 0;
    minr = 1000000000;
  }
}
