#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, seg[110], sum = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> seg[i];
    sum += seg[i];
  }
  int res = 0;
  for (int i = 0; i <= 10000; i++) {
    res = (int)((double)(sum + i * k) / (n + i) + 0.5);
    if (res >= k) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
