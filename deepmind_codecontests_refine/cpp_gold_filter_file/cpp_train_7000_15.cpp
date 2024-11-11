#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fpmath=sse,sse2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
using llong = long long;
using ullong = unsigned long long;
using ulong = unsigned long;
using namespace std;
template <typename Value, typename Manager,
          typename Alloc = std::allocator<char>>
struct SegmentTreeNode {
  friend Manager;

 private:
  const int left;
  const int right;
  Value value;
  Manager LazyManager;
  SegmentTreeNode *leftChild = nullptr;
  SegmentTreeNode *rightChild = nullptr;
  static Alloc alloc;
  void Push() {
    if (leftChild == nullptr) {
      const int mid = (left + right) >> 1;
      leftChild = (SegmentTreeNode *)alloc.allocate(sizeof(*this));
      rightChild = (SegmentTreeNode *)alloc.allocate(sizeof(*this));
      new (leftChild) SegmentTreeNode(left, mid);
      new (rightChild) SegmentTreeNode(mid + 1, right);
    }
    LazyManager.Push(*leftChild, *rightChild);
  }

 public:
  SegmentTreeNode(const int l, const int r) : left(l), right(r) {
    LazyManager.ConstructValue(*this);
  }
  inline const Manager &GetManager() const { return LazyManager; }
  template <typename T>
  void Update(const int begin, const int end, const T &newValue) {
    if ((end < left) || (right < begin)) return;
    if ((begin <= left) && (right <= end)) {
      LazyManager.Modify(*this, newValue);
      return;
    }
    Push();
    leftChild->Update(begin, end, newValue);
    rightChild->Update(begin, end, newValue);
    value = LazyManager.Apply(leftChild->value, rightChild->value);
  }
  Value Get(const int begin, const int end) {
    if ((end < left) || (right < begin)) return LazyManager.SpecialValue;
    if ((begin <= left) && (right <= end)) {
      return value;
    }
    Push();
    return LazyManager.Apply(leftChild->Get(begin, end),
                             rightChild->Get(begin, end));
  }
  template <typename Pred>
  int Search(const int begin, const int end, Pred func) {
    if ((end < left) || (right < begin)) return INT_MAX;
    if ((begin <= left) && (right <= end)) {
      if (!func(value)) return INT_MAX;
      if (leftChild == nullptr)
        return left;
      else {
        return min(leftChild->Search(begin, end, func),
                   rightChild->Search(begin, end, func));
      }
    }
    Push();
    return min(leftChild->Search(begin, end, func),
               rightChild->Search(begin, end, func));
  }
  ~SegmentTreeNode() {
    if (leftChild != nullptr) {
      leftChild->~SegmentTreeNode();
      rightChild->~SegmentTreeNode();
      alloc.deallocate((char *)leftChild, sizeof(*this));
      alloc.deallocate((char *)rightChild, sizeof(*this));
    }
  }
};
template <typename Value, typename Manager, typename Alloc>
Alloc SegmentTreeNode<Value, Manager, Alloc>::alloc;
struct LongMinManager {
  using className = LongMinManager;
  using T = llong;
  static const T SpecialValue = LLONG_MAX;
  llong lazy = 0;
  inline T Apply(const T &x, const T &y) const { return min(x, y); }
  template <typename Alloc>
  inline void Modify(SegmentTreeNode<T, className, Alloc> &x, const T &y) {
    lazy += y;
    x.value += y;
  }
  template <typename Alloc>
  inline void Push(SegmentTreeNode<T, className, Alloc> &left,
                   SegmentTreeNode<T, className, Alloc> &right) {
    left.LazyManager.Modify(left, lazy);
    right.LazyManager.Modify(right, lazy);
    lazy = 0;
  }
  template <typename Alloc>
  inline void ConstructValue(SegmentTreeNode<T, className, Alloc> &x) const {
    x.value = T();
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int count = (int)ceil(n / 2.0);
  vector<int> a(n);
  copy_n(istream_iterator<int>(cin), count, a.begin());
  int x;
  cin >> x;
  fill(a.begin() + count, a.end(), x);
  int k = count;
  ;
  ;
  ;
  llong sum = accumulate(a.begin(), a.begin() + k, 0ll);
  SegmentTreeNode<llong, LongMinManager> root(0, n + 1);
  for (int i = 0; i + k <= n; ++i) {
    root.Update(i, i, sum);
    if (i + k < n) {
      sum += (llong)a[i + k] - a[i];
    }
  }
  llong backIndex = n - k;
  while (backIndex >= 0) {
    if (root.Get(0, backIndex) > 0) {
      cout << k;
      return 0;
    }
    root.Update(0, backIndex, x);
    root.Update(backIndex, backIndex, 1e18);
    --backIndex;
    ++k;
  }
  cout << -1;
  return 0;
}
