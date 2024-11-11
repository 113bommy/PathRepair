#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mid = (n - 1) / 2;
  int olen = n;
  int steps = 0;
  while (mid >= 0 && mid < olen) {
    if (a[mid] < x) {
      while (mid < olen && a[mid] < x) {
        mid += 1 - n % 2;
        n++;
        steps++;
      }
      cout << steps << endl;
      return 0;
    } else {
      while (mid >= 0 && a[mid] > x) {
        mid -= n % 2;
        n--;
        steps++;
      }
      cout << steps << endl;
      return 0;
    }
  }
  return 0;
}
