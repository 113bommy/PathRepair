#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long sum = 0;
  long long rem = y;
  for (int i = 0; i < n - 1; i++) {
    sum++;
    rem--;
  }
  if (rem <= 0 || sum + rem * rem < x) {
    cout << -1;
  } else {
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << "\n";
    }
    cout << rem;
  }
  return 0;
}
