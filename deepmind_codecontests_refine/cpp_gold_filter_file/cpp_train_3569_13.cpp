#include <bits/stdc++.h>
using namespace std;
inline void inc_count(vector<long long>& a, vector<long long>& prefix_sums,
                      int index1, int index2, int& count) {
  if (index2 <= index1 + 1) return;
  if ((a[index1] ^ a[index2]) ==
      (prefix_sums[index2] - prefix_sums[index1 + 1])) {
    count++;
  }
}
int get_count(vector<long long>& a, vector<long long>& prefix_sums, int l,
              int r, int index) {
  if (index == 0) return 0;
  if (r <= l + 2) return 0;
  int count = 0;
  long long mask = (long long)1 << index;
  vector<long long> high_a;
  high_a.push_back(l - 1);
  for (int i = l; i < r; i++) {
    if (a[i] & mask) high_a.push_back(i);
  }
  high_a.push_back(r);
  int high_a_size = high_a.size();
  for (int i = 1; i < high_a_size - 2; i++) {
    inc_count(a, prefix_sums, high_a[i], high_a[i + 1], count);
  }
  for (int i = 1; i < high_a_size - 1; i++) {
    for (int j = high_a[i] + 2; j < high_a[i + 1]; j++) {
      inc_count(a, prefix_sums, high_a[i], j, count);
    }
  }
  for (int i = 1; i < high_a_size - 1; i++) {
    for (int j = high_a[i - 1] + 1; j < high_a[i] - 1; j++) {
      inc_count(a, prefix_sums, j, high_a[i], count);
    }
  }
  for (int i = 1; i < high_a_size - 2; i++) {
    for (int j = high_a[i + 1] + 1; j < high_a[i + 2]; j++) {
      inc_count(a, prefix_sums, high_a[i], j, count);
    }
  }
  for (int i = 2; i < high_a_size - 1; i++) {
    for (int j = high_a[i - 2] + 1; j < high_a[i - 1]; j++) {
      inc_count(a, prefix_sums, j, high_a[i], count);
    }
  }
  for (int i = 0; i < high_a_size - 1; i++) {
    count += get_count(a, prefix_sums, high_a[i] + 1, high_a[i + 1], index - 1);
  }
  return count;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(14);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> prefix_sums(n + 1);
  prefix_sums[0] = 0;
  for (int i = 0; i < n; i++) {
    prefix_sums[i + 1] = prefix_sums[i] + a[i];
  }
  cout << get_count(a, prefix_sums, 0, n, 29) << "\n";
}
