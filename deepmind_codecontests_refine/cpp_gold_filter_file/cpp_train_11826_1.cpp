#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int dist, min = INT_MAX;
  int count = 1;
  for (int i = 0; i < n - 1; i++) {
    dist = abs(v[i + 1] - v[i]);
    if (dist < min) {
      count = 1;
      min = dist;
    } else if (dist == min)
      count++;
  }
  printf("%d %d", min, count);
  return 0;
}
