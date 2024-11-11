#include <bits/stdc++.h>
using namespace std;
int cmp(const int &a, const int &b) { return a > b; }
int a[55555];
int k[10] = {2, 3, 5, 7, 11, 13};
int ans;
int num;
int n;
int main() {
  num = 1;
  cin >> n;
  int lim = 2 * n * n;
  a[0] = 1;
  for (int i = 0; num < n; i++) {
    for (int j = 0; j < num; j++) {
      if (a[j] * k[i] <= lim) {
        a[num++] = a[j] * k[i];
      }
    }
  }
  for (int i = num - 1; i >= num - n; i--) {
    cout << a[i] << " ";
  }
  return 0;
}
