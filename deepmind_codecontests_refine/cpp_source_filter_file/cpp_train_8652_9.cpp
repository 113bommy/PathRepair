#include <bits/stdc++.h>
using namespace std;
bool pos(vector<int>& count, int k, int val, int n) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    c += count[i] / val;
  }
  if (c >= k) return 1;
  return 0;
}
int main() {
  long long n, k;
  cin >> n >> k;
  vector<int> arr(n);
  map<int, int> my;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    my[arr[i]]++;
  }
  vector<int> count;
  for (auto i : my) {
    count.push_back(i.second);
  }
  sort(count.begin(), count.end());
  int high = 200006;
  int low = 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (pos(count, k, mid, count.size())) {
      low = mid + 1;
    } else
      high = mid - 1;
  }
  int cur = 0;
  for (auto i : my) {
    int mn = i.second / high;
    while (cur <= k and mn > 0) {
      cout << i.first << " ";
      mn--;
      cur++;
    }
  }
  return 0;
}
