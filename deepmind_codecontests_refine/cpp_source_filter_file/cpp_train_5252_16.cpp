#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[3] = {0, 0, 0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    a[k % 3]++;
  }
  cout << max(min(a[1], a[2]), a[0] / 2) << endl;
  return 0;
}
