#include <bits/stdc++.h>
constexpr int NO_UPDATE = std::numeric_limits<int>::min();
struct Node {
  int left;
  int right;
  int update_min = NO_UPDATE;
  int update_max = NO_UPDATE;
  int best_max_i = std::numeric_limits<int>::max();
  int best_min_i = std::numeric_limits<int>::max();
  int best_score = std::numeric_limits<int>::max();
};
class Tree {
 public:
  Tree(int n) : n_(CalcSize(n)), nodes_(n_ << 1) {
    for (int i = 0; i < n_; i++) {
      nodes_[n_ + i].left = i;
      nodes_[n_ + i].right = i + 1;
    }
    for (int i = n_ - 1; i > 0; i--) {
      nodes_[i].left = nodes_[i << 1].left;
      nodes_[i].right = nodes_[(i << 1) + 1].right;
    }
  }
  void UpdateMin(int i, int update_left, int update_right, int value) {
    auto* node = &nodes_[i];
    if (node->left >= update_right || node->right <= update_left) {
      return;
    }
    if (node->left >= update_left && node->right <= update_right) {
      Update(node, value, node->update_max);
      return;
    }
    int child1 = i << 1;
    int child2 = child1 + 1;
    Update(&nodes_[child1], node->update_min, node->update_max);
    Update(&nodes_[child2], node->update_min, node->update_max);
    node->update_min = NO_UPDATE;
    node->update_max = NO_UPDATE;
    UpdateMin(child1, update_left, update_right, value);
    UpdateMin(child2, update_left, update_right, value);
    node->best_min_i =
        std::min(nodes_[child1].best_min_i, nodes_[child2].best_min_i);
    node->best_score =
        std::min(nodes_[child1].best_score, nodes_[child2].best_score);
  }
  void UpdateMax(int i, int update_left, int update_right, int value) {
    auto* node = &nodes_[i];
    if (node->left >= update_right || node->right <= update_left) {
      return;
    }
    if (node->left >= update_left && node->right <= update_right) {
      Update(node, node->update_min, value);
      return;
    }
    int child1 = i << 1;
    int child2 = child1 + 1;
    Update(&nodes_[child1], node->update_min, node->update_max);
    Update(&nodes_[child2], node->update_min, node->update_max);
    node->update_min = NO_UPDATE;
    node->update_max = NO_UPDATE;
    UpdateMax(child1, update_left, update_right, value);
    UpdateMax(child2, update_left, update_right, value);
    node->best_max_i =
        std::min(nodes_[child1].best_max_i, nodes_[child2].best_max_i);
    node->best_score =
        std::min(nodes_[child1].best_score, nodes_[child2].best_score);
  }
  static void Update(Node* node, int min, int max) {
    if (min != NO_UPDATE) {
      node->update_min = min;
      node->best_min_i = -min + node->left;
      node->best_score = node->best_max_i - min;
    }
    if (max != NO_UPDATE) {
      node->update_max = max;
      node->best_max_i = max + node->left;
      node->best_score = node->best_min_i + max;
    }
  }
  int QueryBestScore(int i, int query_left, int query_right, int update_min,
                     int update_max) {
    const auto* const node = &nodes_[i];
    if (node->left >= query_right || node->right <= query_left) {
      return std::numeric_limits<int>::max();
    }
    if (update_min == NO_UPDATE) {
      update_min = node->update_min;
    }
    if (update_max == NO_UPDATE) {
      update_max = node->update_max;
    }
    if (query_left <= node->left && query_right >= node->right) {
      if (update_min != NO_UPDATE) {
        if (update_max != NO_UPDATE) {
          return update_max - update_min + node->left;
        }
        return node->best_max_i - update_min;
      }
      if (update_max != NO_UPDATE) {
        return node->best_min_i + update_max;
      }
      return node->best_score;
    }
    int child1 = i << 1;
    int child2 = 1 + (i << 1);
    return std::min(
        QueryBestScore(child1, query_left, query_right, update_min, update_max),
        QueryBestScore(child2, query_left, query_right, update_min,
                       update_max));
  }
  static int CalcSize(int x) {
    int n;
    for (n = 1; n < x; n <<= 1)
      ;
    return n;
  }

 private:
  const int n_;
  std::vector<Node> nodes_;
};
class FindPrev {
 public:
  FindPrev(const std::vector<int>* array) : array_(array) {}
  std::tuple<int, int, int> Add(int i) {
    auto value = (*array_)[i];
    auto prev_eq_it = prev_equal_.find(value);
    int prev_eq = -1;
    if (prev_eq_it != prev_equal_.end()) {
      prev_eq = prev_eq_it->second;
    }
    prev_equal_[value] = i;
    int prev_ge = -1;
    while (!prev_greater_.empty() && (*array_)[prev_greater_.top()] < value) {
      prev_greater_.pop();
    }
    if (!prev_greater_.empty()) {
      prev_ge = prev_greater_.top();
    }
    prev_greater_.push(i);
    int prev_le = -1;
    while (!prev_smaller_.empty() && (*array_)[prev_smaller_.top()] > value) {
      prev_smaller_.pop();
    }
    if (!prev_smaller_.empty()) {
      prev_le = prev_smaller_.top();
    }
    prev_smaller_.push(i);
    return std::make_tuple(prev_eq, prev_ge, prev_le);
  }

 private:
  std::unordered_map<int, int> prev_equal_;
  std::stack<int> prev_greater_;
  std::stack<int> prev_smaller_;
  const std::vector<int>* const array_;
};
std::pair<int, int> arithmetic_div(int x, int y) {
  auto r = x % y;
  if (x >= 0) return {x / y, r};
  return {(x + 1) / y - 1, r ? y + r : 0};
}
int bsearch(int l, int r, std::function<bool(int j)> f) {
  while (l < r) {
    int mid = (l + r) >> 1;
    if (f(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
  int n, k, d;
  std::cin >> n >> k >> d;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int best_len = 1;
  int best_i = 0;
  if (d == 0) {
    int prev = a[0];
    int prev_i = 0;
    for (int i = 1; i < a.size(); i++) {
      if (a[i] == prev) {
        if (i - prev_i + 1 > best_len) {
          best_len = i - prev_i + 1;
          best_i = prev_i;
        }
      } else {
        prev_i = i;
        prev = a[i];
      }
    }
    std::cout << best_i + 1 << " " << best_i + best_len << std::endl;
    return 0;
  }
  FindPrev prev(&a);
  Tree tree(n);
  int left_bound = 0;
  int current_rem = 0;
  for (int i = 0; i < n; i++) {
    auto qr = arithmetic_div(a[i], d);
    if (i > 0 && qr.second != current_rem) {
      left_bound = i;
    }
    current_rem = qr.second;
    auto p = prev.Add(i);
    left_bound = std::max(1 + std::get<0>(p), left_bound);
    auto update_max_from = std::max(1 + std::get<1>(p), left_bound);
    auto update_min_from = std::max(1 + std::get<2>(p), left_bound);
    tree.UpdateMax(1, update_max_from, i + 1, qr.first);
    tree.UpdateMin(1, update_min_from, i + 1, qr.first);
    auto found = bsearch(left_bound, i + 1, [i, &tree, k, left_bound](int j) {
      return tree.QueryBestScore(1, left_bound, j + 1, NO_UPDATE, NO_UPDATE) -
                 i <=
             k;
    });
    if (i - found + 1 > best_len) {
      best_len = i - found + 1;
      best_i = found;
    }
  }
  std::cout << best_i + 1 << " " << best_i + best_len << std::endl;
  return 0;
}
