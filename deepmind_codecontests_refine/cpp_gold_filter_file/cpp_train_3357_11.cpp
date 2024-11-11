#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q, r, s;
  cin >> q;
  while (q--) {
    cin >> r >> s;
    if (s % (r - 1) == 0)
      cout << (s + ((s / (r - 1) - 1))) << "\n";
    else
      cout << (s + (s / (r - 1))) << "\n";
  }
  return 0;
}
