#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> numbers;
long long check(long long med) {
  long long work = 0;
  for (long long i = n / 2; i < n; i++) {
    if (med - numbers[i] > 0) {
      work += (med - numbers[i]);
    }
    if (work > k) {
      return false;
    }
  }
  return true;
}
int32_t main() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    long long val;
    cin >> val;
    numbers.push_back(val);
  }
  sort(numbers.begin(), numbers.end());
  long long low, high;
  low = 0;
  high = 2e9;
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    if (check(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << "\n";
}
