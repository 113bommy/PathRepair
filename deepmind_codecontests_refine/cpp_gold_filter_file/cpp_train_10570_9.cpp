#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned n;
  unsigned maxnum = 0;
  unsigned long long sum = 0;
  cin >> n;
  unsigned kek;
  for (int i = 0; i < n; i++) {
    cin >> kek;
    if (kek > maxnum) {
      maxnum = kek;
    }
    sum += kek;
  }
  cout << '\n';
  cout << 2 * maxnum - sum + 1;
  cout << '\n';
  return 0;
}
