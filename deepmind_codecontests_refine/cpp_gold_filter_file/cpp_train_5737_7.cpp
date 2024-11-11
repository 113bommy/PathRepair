#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a, b;
  long long left[n];
  long long right[n];
  for (long long i = 0; i < n; i++) {
    cin >> a >> b;
    left[i] = a;
    right[i] = b;
  }
  long long largest = INT_MIN;
  long long second_lar = INT_MIN;
  long long smallest = INT_MAX;
  long long second_small = INT_MAX;
  for (long long i = 0; i < n; i++) {
    if (left[i] >= largest) {
      second_lar = largest;
      largest = left[i];
    } else if (left[i] >= second_lar) {
      second_lar = left[i];
    }
    if (right[i] <= smallest) {
      second_small = smallest;
      smallest = right[i];
    } else if (right[i] <= second_small)
      second_small = right[i];
  }
  long long mx = 0;
  for (long long i = 0; i < n; i++) {
    long long k1 = largest;
    long long k2 = smallest;
    if (left[i] == k1) {
      k1 = second_lar;
    }
    if (right[i] == k2) {
      k2 = second_small;
    }
    mx = max(mx, (k2 - k1));
  }
  cout << mx << endl;
  return 0;
}
