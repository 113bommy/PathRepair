#include <bits/stdc++.h>
using namespace std;
int money[100005];
int main() {
  int n, k;
  cin >> n >> k;
  int j = 0;
  int lc = -1;
  for (int i = 0; i < n; i++) {
    cin >> money[i];
    if (j < k && money[i] < 0) {
      money[i] = -money[i];
      j++;
      lc = i;
    }
  }
  if (j < k) {
    if ((k - j) % 2) {
      if (lc > -1 && lc + 1 < n && money[lc + 1] < money[lc]) {
        lc = lc + 1;
      }
      money[lc] = -money[lc];
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += money[i];
  }
  cout << sum << endl;
  return 0;
}
