#include <bits/stdc++.h>
int32_t* data;
std::vector<int32_t>* segtree;
void build(int32_t node, int32_t left, int32_t right) {
  if (right - left == 1) {
    segtree[node] = {data[left]};
    return;
  }
  int32_t m = (left + right) / 2;
  build(node * 2 + 1, left, m);
  build(node * 2 + 2, m, right);
  segtree[node].resize(right - left);
  std::merge(segtree[node * 2 + 1].begin(), segtree[node * 2 + 1].end(),
             segtree[node * 2 + 2].begin(), segtree[node * 2 + 2].end(),
             segtree[node].begin());
}
int32_t query(int32_t node, int32_t left, int32_t right, int32_t query_left,
              int32_t query_right, int32_t param) {
  if (right <= query_left || left >= query_right) return 0;
  if (left >= query_left && right <= query_right) {
    return right - left -
           (std::lower_bound(segtree[node].begin(), segtree[node].end(),
                             param) -
            segtree[node].begin());
  }
  int32_t m = (left + right) / 2;
  return query(node * 2 + 1, left, m, query_left, query_right, param) +
         query(node * 2 + 2, m, right, query_left, query_right, param);
}
struct SparseTable {
  int32_t** table;
  bool min_;
  SparseTable(int32_t* data, int32_t n, bool min) {
    min_ = min;
    int32_t max_level = 0;
    while ((1 << max_level) <= n) max_level++;
    max_level--;
    table = new int32_t*[max_level + 1];
    for (int32_t i = 0; i <= max_level; i++) {
      int32_t length = n - (1 << i) + 1;
      table[i] = new int32_t[length];
      for (int32_t j = 0; j < length; j++)
        if (i == 0)
          table[i][j] = data[j];
        else
          table[i][j] =
              min_ ? std::min(table[i - 1][j], table[i - 1][j + (1 << i) / 2])
                   : std::max(table[i - 1][j], table[i - 1][j + (1 << i) / 2]);
    }
  }
  int32_t query(int32_t left, int32_t right) {
    int32_t level = 0;
    while ((1 << level) <= right - left + 1) level++;
    level--;
    return min_ ? std::min(table[level][left],
                           table[level][right - (1 << level) + 1])
                : std::max(table[level][left],
                           table[level][right - (1 << level) + 1]);
  }
};
int main() {
  int32_t n;
  std::cin >> n;
  int32_t* arr = new int32_t[n];
  for (int32_t i = 0; i < n; i++) std::cin >> arr[i];
  std::map<int32_t, int32_t> last;
  int32_t* next = new int32_t[n];
  for (int32_t i = 0; i < n; i++) next[i] = INT32_MAX;
  for (int32_t i = 0; i < n; i++) {
    auto it = last.find(arr[i]);
    if (it != last.end()) next[it->second] = i;
    last[arr[i]] = i;
  }
  std::set<std::pair<int32_t, int32_t> > unmatched;
  int32_t* prev_bigger = new int32_t[n];
  for (int32_t i = 0; i < n; i++) prev_bigger[i] = INT32_MIN;
  for (int32_t i = n - 1; i >= 0; i--) {
    while (unmatched.size() > 0 && unmatched.begin()->first < arr[i]) {
      prev_bigger[unmatched.begin()->second] = i;
      unmatched.erase(unmatched.begin());
    }
    unmatched.emplace(arr[i], i);
  }
  unmatched.clear();
  int32_t* next_bigger = new int32_t[n];
  for (int32_t i = 0; i < n; i++) next_bigger[i] = INT32_MAX;
  for (int32_t i = 0; i < n; i++) {
    while (unmatched.size() > 0 && unmatched.begin()->first < arr[i]) {
      next_bigger[unmatched.begin()->second] = i;
      unmatched.erase(unmatched.begin());
    }
    unmatched.emplace(arr[i], i);
  }
  SparseTable table1(next, n, true);
  int32_t* num_unique = new int32_t[n];
  for (int32_t i = 0; i < n; i++) {
    int32_t left = 1, right = n - i + 1;
    while (right - left > 1) {
      int32_t m = (left + right) / 2;
      if (table1.query(i, i + m - 1) > i + m - 1)
        left = m;
      else
        right = m;
    }
    num_unique[i] = left;
  }
  data = num_unique;
  segtree = new std::vector<int32_t>[n * 4];
  build(0, 0, n);
  int64_t answer = 0;
  for (int32_t i = 0; i < n; i++) {
    int32_t left = std::max(std::max(0, i - arr[i] + 1), prev_bigger[i] + 1);
    int32_t right = std::min(i + 1, next_bigger[i] - arr[i] + 1);
    if (right <= left) continue;
    answer += query(0, 0, n, left, right, arr[i]);
  }
  std::cout << answer;
  return 0;
}
