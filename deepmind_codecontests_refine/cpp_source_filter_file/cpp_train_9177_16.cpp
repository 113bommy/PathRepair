#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, arr[N], neg;
priority_queue<pair<int, int>> pq;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    if (arr[i] < 0) ++neg;
    pq.push({arr[i], i});
  }
  while (pq.top().first >= 0) {
    auto x = pq.top();
    pq.pop();
    arr[x.second] = -x.first - 1;
    pq.push({-x.first - 1, x.second});
    ++neg;
  }
  if (neg % 2) {
    int mx = -2e9, idx;
    for (int i = 0; i < n; ++i)
      if (arr[i] > mx) {
        mx = arr[i];
        idx = i;
      }
    arr[idx] = -arr[idx] - 1;
  }
  for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
  return 0;
}
