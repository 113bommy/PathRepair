#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, k, right, left, mid;
  cin >> n >> k;
  left = 0, right = 100000000;
  while (left < right) {
    mid = (left + right) / 2;
    unsigned long long V = mid, Sum = mid;
    while (Sum < n && V) {
      V /= k;
      Sum += V;
    }
    if (Sum >= n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << left << endl;
}
