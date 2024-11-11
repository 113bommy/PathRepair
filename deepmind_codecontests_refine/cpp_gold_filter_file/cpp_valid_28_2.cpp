#include <bits/stdc++.h>
using namespace std;
class DSU {
 public:
  explicit DSU(int size) : size_(size) {
    parent_.resize(size_);
    iota(parent_.begin(), parent_.end(), 0);
    rank_.resize(size_);
  }
  int Size() const { return size_; }
  int Find(int vertex) const {
    return parent_[vertex] == vertex ? vertex
                                     : parent_[vertex] = Find(parent_[vertex]);
  }
  bool Union(int first, int second) {
    first = Find(first);
    second = Find(second);
    if (first == second) {
      return false;
    } else {
      if (rank_[first] < rank_[second]) {
        swap(first, second);
      }
      parent_[second] = first;
      if (rank_[first] == rank_[second]) {
        ++rank_[first];
      }
      --size_;
      return true;
    }
  }

 private:
  int size_;
  mutable vector<int> parent_;
  vector<int> rank_;
};
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (auto& pi : p) {
      cin >> pi;
      --pi;
    }
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
      ++f[(i - p[i] + n) % n];
    }
    vector<int> r;
    for (int k = 0; k < n; ++k) {
      if (f[k] >= n - 2 * m) {
        DSU cc(n);
        for (int i = 0; i < n; ++i) {
          cc.Union(i, (p[i] + k + n) % n);
        }
        if (n - cc.Size() <= m) {
          r.push_back(k);
        }
      }
    }
    cout << r.size();
    for (auto k : r) {
      cout << " " << k;
    }
    cout << "\n";
  }
  return 0;
}
