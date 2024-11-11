#include <bits/stdc++.h>
const int kMaxPointsNum = 1 << 18;
const int kMaxIntervals = 1 << 19;
const int kMaxOperations = 5 * 100000 + 10;
class ITree {
  struct ITreeNode {
    int tot;
    long long sum, aim;
    ITreeNode() : tot(0), sum(0), aim(0){};
  };
  ITreeNode data_[kMaxIntervals];
  const int (&reference_)[kMaxPointsNum];
  int root_left_, root_right_;
  void Insert(int pos, int left, int right, int cursor);
  void Remove(int pos, int left, int right, int cursor);
  ITreeNode Query(int qleft, int qright, int left, int right, int cursor);

 public:
  ITree(const int (&refer)[kMaxPointsNum]) : reference_(refer) {
    root_left_ = 0;
    root_right_ = kMaxPointsNum;
  }
  void Insert(int pos);
  void Remove(int pos);
  long long Query(int qleft, int qright);
};
void ITree::Insert(int pos, int left, int right, int cursor) {
  ITreeNode &current = data_[cursor];
  ++current.tot;
  current.sum += reference_[pos];
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    if (pos < mid)
      Insert(pos, left, mid, cursor * 2);
    else
      Insert(pos, mid, right, cursor * 2 + 1);
    ITreeNode &lc = data_[cursor * 2], &rc = data_[cursor * 2 + 1];
    current.aim = lc.aim + rc.aim + rc.sum * lc.tot - lc.sum * rc.tot;
  }
}
void ITree::Remove(int pos, int left, int right, int cursor) {
  ITreeNode &current = data_[cursor];
  --current.tot;
  current.sum -= reference_[pos];
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    if (pos < mid)
      Remove(pos, left, mid, cursor * 2);
    else
      Remove(pos, mid, right, cursor * 2 + 1);
    ITreeNode &lc = data_[cursor * 2], &rc = data_[cursor * 2 + 1];
    current.aim = lc.aim + rc.aim + rc.sum * lc.tot - lc.sum * rc.tot;
  }
}
ITree::ITreeNode ITree::Query(int qleft, int qright, int left, int right,
                              int cursor) {
  if (qleft <= left && right <= qright) return data_[cursor];
  int mid = (left + right) / 2;
  ITreeNode ln, rn, ret;
  if (qleft < mid) ln = Query(qleft, qright, left, mid, cursor * 2);
  if (qright > mid) rn = Query(qleft, qright, mid, right, cursor * 2 + 1);
  ret.tot = ln.tot + rn.tot;
  ret.sum = ln.sum + rn.sum;
  ret.aim = ln.aim + rn.aim + rn.sum * ln.tot - ln.sum * rn.tot;
  return ret;
}
void ITree::Insert(int pos) { Insert(pos, root_left_, root_right_, 1); }
void ITree::Remove(int pos) { Remove(pos, root_left_, root_right_, 1); }
long long ITree::Query(int qleft, int qright) {
  ITreeNode result = Query(qleft, qright, root_left_, root_right_, 1);
  return result.aim;
}
int n;
int curr_pos[kMaxPointsNum];
int initial_pos[kMaxPointsNum];
int m;
short operations[kMaxOperations][3];
void Read() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", initial_pos + i);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 3; ++j) scanf("%hd", &operations[i][j]);
  }
}
int size = 0;
int slots[kMaxPointsNum];
void Initialize() {
  int i, p, d;
  memmove(curr_pos, initial_pos, sizeof(curr_pos[0]) * n);
  for (i = 0; i < n; ++i) slots[size++] = curr_pos[i];
  for (i = 0; i < m; ++i) {
    if (operations[i][0] == 1) {
      p = --operations[i][1];
      d = operations[i][2];
      curr_pos[p] += d;
      slots[size++] = curr_pos[p];
    }
  }
  std::sort(slots, slots + size);
  size = std::unique(slots, slots + size) - slots;
}
void Run() {
  int i, px, delta, ql, qr;
  ITree *tree = new ITree(slots);
  for (i = 0; i < n; ++i) {
    curr_pos[i] = std::lower_bound(slots, slots + size, initial_pos[i]) - slots;
    tree->Insert(curr_pos[i]);
  }
  for (i = 0; i < m; ++i) {
    if (operations[i][0] == 1) {
      px = operations[i][1];
      delta = operations[i][2];
      tree->Remove(curr_pos[px]);
      curr_pos[px] =
          std::lower_bound(slots, slots + size, slots[curr_pos[px]] + delta) -
          slots;
      tree->Insert(curr_pos[px]);
    } else {
      ql = std::lower_bound(slots, slots + size, operations[i][1]) - slots;
      qr = std::upper_bound(slots, slots + size, operations[i][2]) - slots;
      printf("%I64d\n", tree->Query(ql, qr));
    }
  }
  delete tree;
}
int main() {
  Read();
  Initialize();
  Run();
}
