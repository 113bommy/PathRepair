#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k[105], a, total[105];
  cin >> n;
  for (int i = 0; i < 105; i++) total[i] = 0;
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k[i]; j++) {
      cin >> a;
      total[i] += a;
    }
    total[i] = total[i] * 5 + 15 * k[i];
  }
  int minn = 1000000000;
  for (int i = 0; i < n; i++) {
    if (total[i] < minn) minn = total[i];
  }
  cout << minn << endl;
  return 0;
}
