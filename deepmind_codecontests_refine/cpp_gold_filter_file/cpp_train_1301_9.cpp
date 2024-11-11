#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k;
  cin >> n >> k;
  long number;
  long ans;
  long sum1 = 0;
  long i = 0;
  long sum = 0;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> number;
    sum1 += number;
    v.push_back({10 - (number % 10), number});
  }
  sort(v.begin(), v.end());
  if ((100 * n - sum1) <= k) {
    cout << (10 * n);
  } else {
    while (k && i < n) {
      if (k >= v[i].first) {
        k -= v[i].first;
        v[i].second += v[i].first;
        sum += (v[i].second) / 10;
        i++;
      } else {
        k = 0;
      }
    }
    if (k != 0) {
      sum += ((k - (k % 10)) / 10);
    }
    for (int e = i; e < n; e++) {
      sum += (v[e].second) / 10;
    }
    cout << sum;
  }
  return 0;
}
