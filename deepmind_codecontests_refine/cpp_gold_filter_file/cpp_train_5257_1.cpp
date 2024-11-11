#include <bits/stdc++.h>
using namespace std;
struct Segment {
  int sum, lazy;
};
vector<vector<Segment>> segm_trees;
void print(int N, int treeIndex) {
  for (int i = 0; i < (N); ++i) {
    cout << segm_trees[treeIndex][i].sum << " " << segm_trees[treeIndex][i].lazy
         << endl;
  }
}
void propagate(int treeIndex, int node, int left, int right) {
  int lazy = segm_trees[treeIndex][node].lazy;
  if (lazy > -(1 << 29)) {
    segm_trees[treeIndex][node].sum = lazy * (right - left + 1);
    if (left < right) {
      segm_trees[treeIndex][node * 2 + 1].lazy = lazy;
      segm_trees[treeIndex][node * 2 + 2].lazy = lazy;
    }
    segm_trees[treeIndex][node].lazy = -(1 << 29);
  }
}
void update(int treeIndex, int node, int left, int right, int start, int end,
            int value) {
  propagate(treeIndex, node, left, right);
  if (start <= left && right <= end) {
    segm_trees[treeIndex][node].lazy = value;
  } else {
    int mid = (left + right) / 2;
    if (start <= mid) {
      update(treeIndex, node * 2 + 1, left, mid, start, end, value);
    }
    if (end >= mid + 1) {
      update(treeIndex, node * 2 + 2, mid + 1, right, start, end, value);
    }
    propagate(treeIndex, node * 2 + 1, left, mid);
    propagate(treeIndex, node * 2 + 2, mid + 1, right);
    segm_trees[treeIndex][node].sum = segm_trees[treeIndex][node * 2 + 1].sum +
                                      segm_trees[treeIndex][node * 2 + 2].sum;
  }
}
int query(int treeIndex, int node, int left, int right, int start, int end) {
  propagate(treeIndex, node, left, right);
  if (start <= left && right <= end) {
    return segm_trees[treeIndex][node].sum;
  } else {
    int mid = (left + right) / 2;
    int ans = 0;
    if (start <= mid) {
      ans += query(treeIndex, node * 2 + 1, left, mid, start, end);
    }
    if (end >= mid + 1) {
      ans += query(treeIndex, node * 2 + 2, mid + 1, right, start, end);
    }
    return ans;
  }
  return 0;
}
string solve(int N, int Q, string S, vector<vector<int>> &queries) {
  segm_trees =
      vector<vector<Segment>>(26, vector<Segment>(N * 4, {0, -(1 << 29)}));
  for (int i = 0; i < (N); ++i) {
    int index = S[i] - 'a';
    update(index, 0, 0, N - 1, i, i, 1);
  }
  for (auto q : queries) {
    int start = q[0] - 1;
    int end = q[1] - 1;
    int order = q[2];
    vector<vector<int>> counter;
    for (int i = 0; i < (26); ++i) {
      int count = query(i, 0, 0, N - 1, start, end);
      if (count > 0) {
        counter.push_back({i, count});
      }
      update(i, 0, 0, N - 1, start, end, 0);
    }
    if (order == 0) {
      int s = start;
      for (int i = counter.size() - 1; i >= 0; i--) {
        vector<int> c = counter[i];
        update(c[0], 0, 0, N - 1, s, s + c[1] - 1, 1);
        s = s + c[1];
      }
    } else {
      int s = start;
      for (int i = 0; i < counter.size(); i++) {
        vector<int> c = counter[i];
        update(c[0], 0, 0, N - 1, s, s + c[1] - 1, 1);
        s = s + c[1];
      }
    }
  }
  string ans;
  for (int i = 0; i < (N); ++i) {
    for (int j = 0; j < (26); ++j) {
      int count = query(j, 0, 0, N - 1, i, i);
      if (count > 0) {
        ans += 'a' + j;
      }
    }
  }
  return ans;
};
int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<vector<int>> queries;
  for (int i = 0; i < (Q); ++i) {
    int left, right, order;
    cin >> left >> right >> order;
    queries.push_back({left, right, order});
  }
  string ans = solve(N, Q, S, queries);
  cout << ans << endl;
};
