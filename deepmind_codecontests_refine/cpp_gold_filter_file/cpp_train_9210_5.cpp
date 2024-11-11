#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
 private:
  int _num;
  vector<long long int> _data;
  vector<long long int> _propagation;
  long long int query(int l, int r, int index, int left_bound,
                      int right_bound) {
    if (l == left_bound && r == right_bound) return _data[index];
    int mid = (left_bound + right_bound) / 2;
    if (_propagation[index]) {
      update(left_bound, mid, _propagation[index], index * 2 + 1, left_bound,
             mid);
      update(mid, right_bound, _propagation[index], index * 2 + 2, mid,
             right_bound);
    }
    _propagation[index] = 0;
    if (r <= mid)
      return query(l, r, index * 2 + 1, left_bound, mid);
    else if (l >= mid)
      return query(l, r, index * 2 + 2, mid, right_bound);
    else
      return min(query(l, mid, index * 2 + 1, left_bound, mid),
                 query(mid, r, index * 2 + 2, mid, right_bound));
  }
  void update(int l, int r, long long int value, int index, int left_bound,
              int right_bound) {
    if (l == left_bound && r == right_bound) {
      _propagation[index] += value;
      _data[index] += value;
      return;
    }
    int mid = (left_bound + right_bound) / 2;
    if (_propagation[index]) {
      update(left_bound, mid, _propagation[index], index * 2 + 1, left_bound,
             mid);
      update(mid, right_bound, _propagation[index], index * 2 + 2, mid,
             right_bound);
    }
    _propagation[index] = 0;
    if (r <= mid) {
      update(l, r, value, index * 2 + 1, left_bound, mid);
    } else if (l >= mid) {
      update(l, r, value, index * 2 + 2, mid, right_bound);
    } else {
      update(l, mid, value, index * 2 + 1, left_bound, mid);
      update(mid, r, value, index * 2 + 2, mid, right_bound);
    }
    _data[index] = min(_data[index * 2 + 1], _data[index * 2 + 2]);
  }

 public:
  SegmentTree(int num) : _num(num), _data(num * 4), _propagation(num * 4, 0) {}
  void update(int index, long long int value) {
    update(index, index + 1, value, 0, 0, _num);
  }
  void update(int l, int r, long long int value) {
    update(l, r, value, 0, 0, _num);
  }
  long long int query(int index) { return query(0, index + 1); }
  long long int query(int l, int r) {
    if (l < 0 || r > _num) return -1;
    return query(l, r, 0, 0, _num);
  }
};
int main() {
  int N;
  cin >> N;
  SegmentTree tree(N + 1);
  for (int i = 0; i < N; i++) {
    int value;
    cin >> value;
    tree.update(i, value);
  }
  int op;
  cin >> op;
  string str;
  getline(cin, str);
  while (op--) {
    getline(cin, str);
    istringstream iss(str);
    int l, r, v;
    iss >> l >> r;
    if (iss.eof()) {
      long long int minimum;
      if (l > r)
        minimum = min(tree.query(l, N), tree.query(0, r + 1));
      else
        minimum = tree.query(l, r + 1);
      cout << minimum << "\n";
    } else {
      iss >> v;
      if (l > r) {
        tree.update(l, N, v);
        tree.update(0, r + 1, v);
      } else
        tree.update(l, r + 1, v);
    }
  }
  return 0;
}
