#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::max;
using std::sort;
using std::vector;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n; j++) {
    cin >> b[j];
  }
  vector<int> diffs(n);
  for (int i = 0; i < n; i++) {
    diffs[i] = a[i] - b[i];
  }
  sort(diffs.begin(), diffs.end());
  int good_pairs = 0;
  int start = 0;
  for (int end = n - 1; end > 0 && diffs[end] >= 0; end--) {
    for (start; start < end && diffs[start] + diffs[end] <= 0; start++) {
    }
    if (start == end) {
      break;
    } else {
      good_pairs += end - start;
    }
  }
  cout << good_pairs << '\n';
  return 0;
}
