#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int maxx = 2000000;
  vector<int> frequency(maxx, 0);
  vector<int> val(n + 1, 0);
  for (int i = 1; i < n; i++) {
    cin >> val[i];
  }
  int left = 1;
  int right = 1;
  int distinct = 0;
  int best_left = 1;
  int best_right = 1;
  int best_distance = 0;
  while (right <= n) {
    frequency[val[right]]++;
    if (frequency[val[right]] == 1) distinct++;
    while (distinct > k) {
      frequency[val[left]]--;
      if (frequency[val[left]] == 0) distinct--;
      left++;
    }
    if ((right - left) + 1 > best_distance) {
      best_left = left;
      best_right = right;
      best_distance = (right - left) + 1;
    }
    right++;
  }
  cout << best_left << " " << best_right;
  return 0;
}
