#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, prev = 0, curr, count = 0, e = 0;
  cin >> n;
  while (--n) {
    cin >> curr;
    if (curr < prev) {
      e += prev - curr;
    } else {
      if (e >= curr - prev) {
        e -= curr - prev;
      } else {
        count += curr - prev - e;
        e = 0;
      }
    }
    prev = curr;
  }
  cout << count;
  return 0;
}
