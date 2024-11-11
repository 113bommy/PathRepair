#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int low = 1, high = n;
  while (low < high) {
    long long sum = 0;
    long long v = (low + high) / 2;
    int k_p = 1;
    for (int p = 0; k_p <= v; ++p) {
      sum += v / k_p;
      k_p *= k;
    }
    bool ok = sum >= n;
    if (!ok) {
      low = v;
    } else {
      high = v;
    }
    if (high - low == 1) {
      break;
    }
  }
  cout << high << '\n';
  return 0;
}
