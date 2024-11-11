#include <bits/stdc++.h>
using namespace std;
using namespace std;
using int64 = long long int;
const int kModulo = 1000000007;
struct Edge {
  int from, to;
};
vector<int> Inverse(const vector<int>& a) {
  const int n = a.size();
  vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    result[a[i] - 1] = i;
  }
  return result;
}
vector<int> ComputePhi(const int n) {
  vector<int> phi(n + 1);
  for (int i = 0; i <= n; ++i) {
    phi[i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    if (phi[i] != i) {
      continue;
    }
    for (int j = i; j <= n; j += i) {
      phi[j] = (phi[j] / i) * (i - 1);
    }
  }
  return phi;
}
vector<vector<int>> ComputeDivisors(const int n) {
  vector<vector<int>> divisors(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      divisors[j].push_back(i);
    }
  }
  return divisors;
}
int ModInverse(const int value, const int modulo) {
  int u = value;
  int v = modulo;
  int p1 = 1, q1 = 0;
  int p2 = 0, q2 = 1;
  while (v != 0) {
    const int q = u / v;
    const int p3 = p1 - q * p2;
    const int q3 = q1 - q * q2;
    const int r = u - q * v;
    u = v;
    v = r;
    p1 = p2;
    p2 = p3;
    q1 = q2;
    q2 = q3;
  }
  if (p1 < 0) {
    p1 += modulo;
  }
  if (p1 >= modulo) {
    p1 -= modulo;
  }
  return p1;
}
vector<int64> ComputeCoefs(const vector<int>& phi) {
  const int n = phi.size();
  vector<int> mu(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] != i - 1) {
      continue;
    }
    for (int j = i; j <= n; j += i) {
      mu[j] = -mu[j];
    }
    const int64 ii = static_cast<int64>(i) * i;
    for (int64 j = ii; j <= n; j += ii) {
      mu[j] = 0;
    }
  }
  vector<int64> c(n + 1);
  for (int g = 1; g <= n; ++g) {
    const int64 cur = (g * ModInverse(phi[g], kModulo)) % kModulo;
    for (int d = g; d <= n; d += g) {
      c[d] += mu[d / g] * cur;
      if (c[d] < 0) {
        c[d] += kModulo;
      }
      if (c[d] >= kModulo) {
        c[d] -= kModulo;
      }
    }
  }
  return c;
}
class Tree {
 public:
  explicit Tree(const vector<int>& a)
      : a_(a),
        a_inv_(Inverse(a)),
        phi_(ComputePhi(a.size())),
        divisors_(ComputeDivisors(a.size())),
        coef_(ComputeCoefs(phi_)),
        edges_(a.size()) {}
  void AddEdge(const int from, const int to) {
    edges_[from].push_back({from, to});
    edges_[to].push_back({to, from});
  }
  int Build() {
    const int n = edges_.size();
    layer_.assign(n, n);
    centroid_parent_.assign(n, -1);
    subtree_size_.assign(n, -1);
    Build(0, -1, 0);
    int max_layer = 0;
    for (int node = 0; node < n; ++node) {
      max_layer = max(max_layer, layer_[node]);
    }
    for (int layer = 0; layer <= max_layer; ++layer) {
      root_.assign(n, -1);
      root_child_.assign(n, -1);
      root_depth_.assign(n, -1);
      subtree_.assign(n, 0);
      for (int node = 0; node < n; ++node) {
        if (layer_[node] == layer) {
          ComputeRootAndRootChild(node, -1, layer, node, -1, 0);
        }
      }
      vector<int64> phi_times_depth(n);
      for (int i = 1; i <= n; ++i) {
        const int u = a_inv_[i - 1];
        phi_times_depth[i - 1] = (2LL * phi_[i] * root_depth_[u]) % kModulo;
      }
      for (int g = 1; g <= n; ++g) {
        for (int i = g; i <= n; i += g) {
          const int node = a_inv_[i - 1];
          const int64 value = (coef_[g] * phi_[i]) % kModulo;
          const int root = root_[node];
          const int root_child = root_child_[node];
          if (root != -1) {
            subtree_[root] += value;
            if (subtree_[root] >= kModulo) {
              subtree_[root] -= kModulo;
            }
          }
          if (root_child != -1) {
            subtree_[root_child] += value;
            if (subtree_[root_child] >= kModulo) {
              subtree_[root_child] -= kModulo;
            }
          }
        }
        for (int i = g; i <= n; i += g) {
          const int u = a_inv_[i - 1];
          const int root = root_[u];
          if (root == -1) {
            continue;
          }
          const int root_child = root_child_[u];
          int64 cur_answer = subtree_[root];
          if (root_child != -1) {
            cur_answer -= subtree_[root_child];
          }
          answer_ = (answer_ + cur_answer * phi_times_depth[i - 1]) % kModulo;
        }
        for (int i = g; i <= n; i += g) {
          const int node = a_inv_[i - 1];
          if (root_[node] != -1) {
            subtree_[root_[node]] = 0;
          }
          if (root_child_[node] != -1) {
            subtree_[root_child_[node]] = 0;
          }
        }
      }
    }
    answer_ = (answer_ * ModInverse(n, kModulo)) % kModulo;
    answer_ = (answer_ * ModInverse(n - 1, kModulo)) % kModulo;
    if (answer_ < 0) {
      answer_ = answer_ + kModulo;
    }
    if (answer_ >= kModulo) {
      answer_ = answer_ - kModulo;
    }
    return answer_;
  }

 private:
  void Build(const int node, const int parent, const int layer) {
    const int centroid = FindCentroid(node, layer);
    layer_[centroid] = layer;
    centroid_parent_[centroid] = parent;
    for (const Edge& edge : edges_[centroid]) {
      const int child = edge.to;
      if (layer_[child] >= layer) {
        Build(child, centroid, layer + 1);
      }
    }
  }
  int FindCentroid(const int node, const int layer) {
    const int max_size = ComputeSubtreeSize(node, -1, layer) / 2;
    int parent = -1;
    int centroid = node;
    while (true) {
      bool found = false;
      for (const Edge& edge : edges_[centroid]) {
        const int child = edge.to;
        if (layer_[child] < layer || child == parent) {
          continue;
        }
        if (subtree_size_[child] > max_size) {
          parent = centroid;
          centroid = child;
          found = true;
          break;
        }
      }
      if (!found) {
        return centroid;
      }
    }
  }
  int ComputeSubtreeSize(const int node, const int parent, const int layer) {
    int size = 1;
    for (const Edge& edge : edges_[node]) {
      const int child = edge.to;
      if (layer_[child] < layer || child == parent) {
        continue;
      }
      size += ComputeSubtreeSize(child, node, layer);
    }
    subtree_size_[node] = size;
    return size;
  }
  void ComputeRootAndRootChild(const int node, const int parent,
                               const int layer, const int root,
                               const int root_child, const int depth) {
    root_[node] = root;
    root_child_[node] = root_child;
    root_depth_[node] = depth;
    for (const Edge& edge : edges_[node]) {
      const int child = edge.to;
      if (layer_[child] < layer || child == parent) {
        continue;
      }
      ComputeRootAndRootChild(child, node, layer, root,
                              root_child != -1 ? root_child : child, depth + 1);
    }
  }
  const vector<int> a_;
  const vector<int> a_inv_;
  const vector<int> phi_;
  const vector<vector<int>> divisors_;
  const vector<int64> coef_;
  vector<vector<Edge>> edges_;
  vector<int> layer_;
  vector<int> centroid_parent_;
  vector<int> subtree_size_;
  vector<int> root_;
  vector<int> root_child_;
  vector<int> root_depth_;
  vector<int64> subtree_;
  int answer_ = 0;
};
namespace io {
char* position_;
char* buffer_limit_;
bool FetchChunk() {
  static char buffer_[1024];
  const auto count = fread(buffer_, sizeof(char), 1024, stdin);
  if (count > 0) {
    buffer_limit_ = buffer_ + count;
  } else {
    buffer_[0] = '\0';
    buffer_limit_ = buffer_ + 1;
  }
  position_ = buffer_;
  return count > 0;
}
const bool unused_ = FetchChunk();
template <typename T>
T Read() {
  while ('\0' <= *position_ && *position_ <= ' ') {
    if (++position_ == buffer_limit_) {
      FetchChunk();
    };
  }
  const bool negate = (*position_ == '-');
  if (negate) {
    if (++position_ == buffer_limit_) {
      FetchChunk();
    };
  }
  T result = 0;
  while ('0' <= *position_ && *position_ <= '9') {
    result = 10 * result + (*position_ - '0');
    if (++position_ == buffer_limit_) {
      FetchChunk();
    };
  }
  return negate ? -result : result;
}
string ReadWord() {
  while ('\0' <= *position_ && *position_ <= ' ') {
    if (++position_ == buffer_limit_) {
      FetchChunk();
    };
  }
  string result;
  while (!('\0' <= *position_ && *position_ <= ' ')) {
    result.push_back(*position_);
    if (++position_ == buffer_limit_) {
      FetchChunk();
    };
  }
  return result;
}
}  // namespace io
int main() {
  const int n = io::Read<int>();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = io::Read<int>();
  }
  Tree t(a);
  for (int i = 0; i < n - 1; ++i) {
    const int u = io::Read<int>() - 1;
    const int v = io::Read<int>() - 1;
    t.AddEdge(u, v);
  }
  cout << t.Build() << "\n";
  return 0;
}
