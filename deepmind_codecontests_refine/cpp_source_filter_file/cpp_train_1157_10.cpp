#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  vector<long long> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  long long mn = 100000L;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      long long val;
      if (i > j) {
        val = 4 * i;
      } else {
        val = 4 * j;
      }
      sum += v[j] * val;
    }
    if (sum < mn) {
      mn = sum;
    }
  }
  cout << mn;
  return 0;
}
