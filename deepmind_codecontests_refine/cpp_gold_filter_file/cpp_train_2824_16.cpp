#include <bits/stdc++.h>
using namespace std;
void no() {
  cout << "NO";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long best = 0;
  long long x = 0;
  long long last = -1;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    if (c == last) {
      x = 1;
    } else {
      ++x;
      best = max(best, x);
    }
    last = c;
  }
  cout << best;
  return 0;
}
