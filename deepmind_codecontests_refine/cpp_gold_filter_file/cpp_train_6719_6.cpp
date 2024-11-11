#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  p--;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int count = 0;
  int low, high;
  if (a[p] == 1) count++;
  if (1) {
    low = p - 1;
    high = p + 1;
    while (low >= 0 && high < n) {
      if (a[low] == 1 && a[high] == 1) {
        count += 2;
      }
      low--;
      high++;
    }
    if (low < 0) {
      while (high != n) {
        if (a[high] == 1) {
          count++;
        }
        high++;
      }
    }
    if (high == n) {
      while (low != -1) {
        if (a[low] == 1) {
          count++;
        }
        low--;
      }
    }
  }
  cout << count;
}
