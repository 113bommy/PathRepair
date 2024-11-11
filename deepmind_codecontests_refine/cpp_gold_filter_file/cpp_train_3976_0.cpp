#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned int T;
  cin >> T;
  while (T--) {
    unsigned int s, i, e;
    cin >> s >> i >> e;
    unsigned int a = (s + i + e - 1) / 2;
    cout << (i <= a ? min(a - i, e) + 1U : 0U) << endl;
  }
  return 0;
}
