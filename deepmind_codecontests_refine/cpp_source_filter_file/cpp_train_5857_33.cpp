#include <bits/stdc++.h>
using namespace std;
void run() {
  long long n, r;
  cin >> n >> r;
  if (n < r) {
    long long ans = ((n) / 2) * (n - 1) + ((n) % 2) * ((n - 1) / 2) + 1;
    cout << ans << endl;
  } else {
    long long ans = ((r + 1) / 2) * r + ((r + 1) % 2) * (r / 2);
    cout << ans << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    run();
    t--;
  }
  return 0;
}
