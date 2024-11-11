#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::rel_ops::operator>;
using namespace std;
int findNextDegree(int n) {
  int i = 1;
  while (i < n) {
    i *= 2;
  }
  return i;
}
class FenvikTree {
  vector<int> tree;
  int divisor_is_power_of_two(int n) { return (n + 1) - ((n + 1) & n); }

 public:
  FenvikTree(int n) : tree(vector<int>(findNextDegree(n), 0)) {
    for (int i = 0; i < n; ++i) {
      tree[i] = divisor_is_power_of_two(i);
    }
  }
  void addValue(int index, int value) {
    int i = index;
    while (i < tree.size()) {
      tree[i] += value;
      i += divisor_is_power_of_two(i);
    }
  }
  int getSum(int index) {
    int sum = 0;
    while (index >= 0) {
      sum += tree[index];
      index -= divisor_is_power_of_two(index);
    }
    return sum;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> poss(n), need_to_remove(n, 1);
  for (int i = 0; i < n; ++i) {
    int index;
    cin >> index;
    poss[index - 1] = i;
  }
  for (int i = 0; i < k; ++i) {
    int index;
    cin >> index;
    need_to_remove[index - 1] = 0;
  }
  set<int> not_removed;
  not_removed.insert(-1);
  not_removed.insert(n);
  int ans = 0;
  FenvikTree tree(n);
  for (int i = 0; i < n; ++i) {
    if (need_to_remove[i] == 1) {
      set<int>::iterator it_upper = not_removed.upper_bound(poss[i]);
      set<int>::iterator it_lover = it_upper;
      --it_lover;
      ans += tree.getSum(*it_upper - 1) - tree.getSum(*it_lover);
      tree.addValue(poss[i], -1);
    } else {
      not_removed.insert(poss[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
