#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N, Q;
  cin >> N >> Q;
  while (Q--) {
    long long POS;
    cin >> POS;
    while (POS % 2 == 0) POS = N + (POS >> 1);
    cout << (POS + 1) / 2 << '\n';
  }
}
