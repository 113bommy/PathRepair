#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, p, mid, sum, d, diff, ma, index;
  cin >> n >> m;
  vector<long long> v;
  vector<long long> v1;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &p);
    v.push_back(p);
  }
  sort(v.begin(), v.end());
  sum = 0;
  for (i = 0; i < v.size(); i++) {
    sum = sum + v[i];
    v1.push_back(sum);
  }
  ma = 0;
  for (i = 0; i < v.size(); i++) {
    long long low = 0, high = i;
    while (low <= high) {
      mid = (low + high) / 2;
      long long cal = (i - mid) + 1;
      cal = cal * v[i];
      sum = 0;
      if (mid > 0) sum = v1[mid - 1];
      if (cal - (v1[i] - sum) > m)
        low = mid + 1;
      else
        high = mid - 1;
    }
    if (low <= 0) low = 0;
    low = min(low, i);
    diff = (i - low) + 1;
    if (diff > ma) {
      ma = diff;
      index = v[i];
    } else if (ma == diff)
      index = min(index, ma);
  }
  cout << ma << " " << index << "\n";
}
