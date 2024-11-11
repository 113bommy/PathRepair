#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int t = 0;
  int res = INT_MAX;
  for (int i = 1; i <= 100; i++) {
    int temp = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] > i) {
        temp += (a[j] - 1 - i);
      } else if (a[j] < i) {
        temp += (i - 1 - a[j]);
      } else {
      }
    }
    if (temp < res) {
      t = i;
      res = temp;
    }
  }
  cout << t << " " << res << endl;
  return 0;
}
