#include <bits/stdc++.h>
using namespace std;
long long distance(array<long long, 3> a, array<long long, 3> b) {
  return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) +
         (a[2] - b[2]) * (a[2] - b[2]);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  vector<array<long long, 3>> points(n);
  for (long long i = 0; i < n; i++) {
    cin >> points[i][0] >> points[i][1] >> points[i][2];
  }
  vector<long long> removed(n, false);
  for (long long i = 0; i < n; i++) {
    if (removed[i]) {
      continue;
    }
    long long closest = -1;
    long long min_dist = LLONG_MAX;
    for (long long j = i + 1; j < n; j++) {
      if (removed[j]) {
        continue;
      }
      if (distance(points[i], points[j]) < min_dist) {
        min_dist = distance(points[i], points[j]);
        closest = j;
      }
    }
    cout << i + 1 << " " << closest + 1 << "\n";
    removed[i] = true;
    removed[closest] = true;
  }
  return 0;
}
