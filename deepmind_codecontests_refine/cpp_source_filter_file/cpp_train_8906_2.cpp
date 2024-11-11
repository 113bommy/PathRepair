#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z, a, b, c;
  cin >> x;
  long long int w[70];
  w[0] = 2;
  w[1] = 3;
  for (int i = 2; i < 70; i++) {
    w[i] = w[i - 1] + w[i - 2];
  }
  int low = 0, high = 49, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (w[mid] == x) {
      cout << mid + 1;
      return 0;
    }
    if (mid == low) {
      cout << mid + 1;
      return 0;
    }
    if (w[mid] > x) {
      high = mid;
    }
    if (w[mid] < x) {
      low = mid;
    }
  }
  cout << mid + 1;
  return 0;
}
