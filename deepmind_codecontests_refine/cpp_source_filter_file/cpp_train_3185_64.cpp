#include <bits/stdc++.h>
using namespace std;
int64_t a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b;
  for (int64_t i = 1;; ++i) {
    a *= 3;
    b *= 2;
    if (a >= b) {
      cout << i;
      exit(0);
    }
  }
}
