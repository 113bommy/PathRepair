#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, tp[2];
  bool found = false;
  cin >> n >> k;
  tp[0] = 1;
  tp[1] = 1 + k;
  for (int i = 0; i < k + 1; i++) {
    cout << tp[i % 2] << " ";
    if (i % 2 == 0) {
      tp[0]++;
    } else
      tp[1]--;
  }
  for (int i = k + 2; i <= n; i++) {
    cout << i << " ";
  }
  return 0;
}
