#include <bits/stdc++.h>
using namespace std;
const int DIM = 120005;
struct Node {
  int minim;
  int number;
  int answer;
  int tag;
  int time;
  Node(int _minim = 0, int _number = 0, int _answer = 0, int _tag = 0,
       int _time = 0)
      : minim(_minim),
        number(_number),
        answer(_answer),
        tag(_tag),
        time(_time) {}
} tree[DIM << 2];
void addValue(int node, int value) {
  tree[node].minim += value;
  tree[node].tag += value;
}
void addTime(int node, int value) {
  tree[node].answer += 1LL * tree[node].number * value;
  tree[node].time += value;
}
void pushDown(int node) {
  if (tree[node].tag) {
    addValue(node << 1, tree[node].tag);
    addValue(node << 1 | 1, tree[node].tag);
    tree[node].tag = 0;
  }
  if (tree[node].time) {
    if (tree[node].minim == tree[node << 1].minim) {
      addTime(node << 1, tree[node].time);
    }
    if (tree[node].minim == tree[node << 1 | 1].minim) {
      addTime(node << 1 | 1, tree[node].time);
    }
    tree[node].time = 0;
  }
}
void pushUp(int node) {
  tree[node].minim = min(tree[node << 1].minim, tree[node << 1 | 1].minim);
  tree[node].answer = tree[node << 1].answer + tree[node << 1 | 1].answer;
  tree[node].number = 0;
  if (tree[node].minim == tree[node << 1].minim) {
    tree[node].number += tree[node << 1].number;
  }
  if (tree[node].minim == tree[node << 1 | 1].minim) {
    tree[node].number += tree[node << 1 | 1].number;
  }
}
void build(int node, int left, int right) {
  tree[node].minim = left;
  tree[node].number = 1;
  if (left == right) {
    return;
  }
  int middle = (left + right) >> 1;
  build(node << 1, left, middle);
  build(node << 1 | 1, middle + 1, right);
}
void updateTree(int node, int left, int right, int from, int to, int value) {
  if (from <= left and right <= to) {
    addValue(node, value);
    return;
  }
  int middle = (left + right) >> 1;
  pushDown(node);
  if (from <= middle) {
    updateTree(node << 1, left, middle, from, to, value);
  }
  if (middle < to) {
    updateTree(node << 1 | 1, middle + 1, right, from, to, value);
  }
  pushUp(node);
}
long long queryTree(int node, int left, int right, int from, int to) {
  if (from <= left and right <= to) {
    return tree[node].answer;
  }
  int middle = (left + right) >> 1;
  pushDown(node);
  long long answerLeft(0), answerRight(0);
  if (from <= middle) {
    answerLeft = queryTree(node << 1, left, middle, from, to);
  }
  if (middle < to) {
    answerRight = queryTree(node << 1 | 1, middle + 1, right, from, to);
  }
  return answerLeft + answerRight;
}
long long answer[DIM];
int perm[DIM], stackMax[DIM], stackMin[DIM];
vector<pair<int, int>> queries[DIM];
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int left, right;
    cin >> left >> right;
    queries[right].push_back(make_pair(left, i));
  }
  build(1, 1, n);
  int topMax(0), topMin(0);
  for (int i = 1; i <= n; ++i) {
    addValue(1, -1);
    for (; topMax and perm[stackMax[topMax]] < perm[i]; --topMax) {
      updateTree(1, 1, n, stackMax[topMax - 1] + 1, stackMax[topMax],
                 perm[i] - perm[stackMax[topMax]]);
    }
    stackMax[++topMax] = i;
    for (; topMin and perm[stackMin[topMin]] > perm[i]; --topMin) {
      updateTree(1, 1, n, stackMin[topMin - 1] + 1, stackMin[topMin],
                 perm[stackMin[topMin]] - perm[i]);
    }
    stackMin[++topMin] = i;
    addTime(1, 1);
    for (auto &query : queries[i]) {
      answer[query.second] = queryTree(1, 1, n, query.first, i);
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << answer[i] << "\n";
  }
  return 0;
}
