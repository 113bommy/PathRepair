#include <bits/stdc++.h>
using namespace std;
int n, t, a;
long long sum = 0;
int main() {
  cin >> n >> t;
  for (int i = (0); i < (n); ++i) {
    cin >> a;
    sum += 86400 - a;
    if (sum >= t) {
      cout << n + 1 << endl;
      break;
    }
  }
  return 0;
}
