#include <bits/stdc++.h>
using namespace std;
pair<int, int> func(int a[], int i, int k) {
  if (2 * i <= k) {
    pair<int, int> l1 = func(a, 2 * i, k);
    pair<int, int> r1 = func(a, 2 * i + 1, k);
    int l2 = a[2 * i];
    int r2 = a[2 * i + 1];
    int x = l2 + l1.second;
    int y = r2 + r1.second;
    if (x > y) {
      return make_pair(x - y + l1.first + r1.first, x);
    } else {
      return make_pair(y - x + l1.first + r1.first, y);
    }
  } else
    return make_pair(0, 0);
}
int main() {
  int n, a[100005];
  cin >> n;
  int k = pow(2, n + 1) - 1;
  a[1] = 0;
  for (int i = 2; i <= k; i++) cin >> a[i];
  cout << func(a, 1, k).first << endl;
  return 0;
}
