#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n;
  long long sum = 0;
  cin >> h >> n;
  bool done = false;
  long long min = 0;
  vector<long long> a(n, 0);
  long long max_neg = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (max_neg > sum) {
      max_neg = sum;
    }
    if (sum + h <= 0) {
      done = true;
      min = i + 1;
    }
  }
  if (done) {
    cout << min;
  } else {
    if (sum >= 0) {
      cout << -1;
    } else {
      long long rounds = (h + max_neg) / (-sum);
      long long rem_health = h - (-sum) * rounds;
      long long index = 0;
      long long sum = 0;
      for (long long i = 0;; i++) {
        sum += a[i % n];
        index++;
        if (sum + rem_health <= 0) {
          break;
        }
      }
      long long t = rounds * n + index;
      cout << t;
    }
  }
}
