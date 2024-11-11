#include <bits/stdc++.h>
using namespace std;
template <class T, size_t D>
struct vec : vector<vec<T, D - 1>> {
  template <class... Args>
  vec(size_t n = 0, Args... args)
      : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <class T>
struct vec<T, 1> : vector<T> {
  template <class... Args>
  vec(Args... args) : vector<T>(args...) {}
};
template <class T>
inline bool Minimize(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool Maximize(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
inline int Next(int i, int n) { return i == n - 1 ? 0 : i + 1; }
inline int Prev(int i, int n) { return !i ? n - 1 : i - 1; }
mt19937 rng(static_cast<uint32_t>(
    chrono::steady_clock::now().time_since_epoch().count()));
int Ask(const vec<int, 1>& vertices) {
  cout << "? " << static_cast<int>((vertices).size()) << endl;
  for (auto& u : vertices) {
    cout << u + 1 << ' ';
  }
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}
struct DSU {
  int n_sets;
  vec<int, 1> parents, cardinalities;
  DSU(int t_n_sets)
      : n_sets(t_n_sets), parents(n_sets), cardinalities(n_sets, 1) {
    iota((parents).begin(), (parents).end(), 0);
  }
  int Parent(int i) {
    return i == parents[i] ? i : parents[i] = Parent(parents[i]);
  }
  bool SameSet(int i, int j) { return Parent(i) == Parent(j); }
  bool Unite(int i, int j) {
    i = Parent(i);
    j = Parent(j);
    if (i == j) {
      return false;
    }
    if (cardinalities[i] > cardinalities[j]) {
      swap(i, j);
    }
    --n_sets;
    parents[i] = j;
    cardinalities[j] += cardinalities[i];
    return true;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n_vertices;
  cin >> n_vertices;
  vec<int, 2> neighbors_vertices(n_vertices);
  vec<int, 1> n_edges_prefixes(n_vertices);
  DSU dsu(n_vertices);
  vec<int, 2> elements_sets(n_vertices);
  elements_sets[0].emplace_back(0);
  for (int u = 1; u < n_vertices; ++u) {
    vec<int, 1> sets;
    for (int v = 0; v < u; ++v) {
      if (dsu.Parent(v) == v) {
        sets.emplace_back(v);
      }
    }
    vec<int, 1> prefixes(static_cast<int>((sets).size()));
    for (int i = 0; i < static_cast<int>((sets).size()); ++i) {
      prefixes[i] = n_edges_prefixes[elements_sets[sets[i]].back()] +
                    (i ? prefixes[i - 1] : 0);
    }
    vec<int, 1> connected_sets;
    for (int i = 0; i < static_cast<int>((sets).size()); ++i) {
      int left_index = i, right_index = static_cast<int>((sets).size());
      while (left_index < right_index) {
        int middle_index = (left_index + right_index) >> 1;
        vec<int, 1> vertices;
        vertices.emplace_back(u);
        for (int j = left_index; j <= middle_index; ++j) {
          vertices.insert(vertices.end(), (elements_sets[sets[j]]).begin(),
                          (elements_sets[sets[j]]).end());
        }
        if (Ask(vertices) != prefixes[middle_index] -
                                 (left_index ? prefixes[left_index - 1] : 0)) {
          right_index = middle_index;
        } else {
          left_index = middle_index + 1;
        }
      }
      i = left_index;
      if (i >= static_cast<int>((sets).size())) {
        continue;
      }
      connected_sets.emplace_back(sets[i]);
      left_index = 0,
      right_index = static_cast<int>((elements_sets[sets[i]]).size()) - 1;
      while (left_index < right_index) {
        int middle_index = (left_index + right_index) >> 1;
        vec<int, 1> vertices;
        vertices.emplace_back(u);
        for (int j = 0; j <= middle_index; ++j) {
          vertices.emplace_back(elements_sets[sets[i]][j]);
        }
        if (Ask(vertices) !=
            n_edges_prefixes[elements_sets[sets[i]][middle_index]]) {
          right_index = middle_index;
        } else {
          left_index = middle_index + 1;
        }
      }
      neighbors_vertices[u].emplace_back(elements_sets[sets[i]][left_index]);
      neighbors_vertices[elements_sets[sets[i]][left_index]].emplace_back(u);
    }
    vec<int, 1> new_elements;
    for (auto& connected_set : connected_sets) {
      vec<int, 1> vertices((elements_sets[connected_set]).begin(),
                           (elements_sets[connected_set]).end());
      vertices.emplace_back(u);
      n_edges_prefixes[u] += Ask(vertices);
      dsu.Unite(connected_set, u);
      if (static_cast<int>((new_elements).size())) {
        for (int i = 0;
             i < static_cast<int>((elements_sets[connected_set]).size()); ++i) {
          n_edges_prefixes[elements_sets[connected_set][i]] +=
              n_edges_prefixes[new_elements.back()];
        }
      }
      new_elements.insert(new_elements.end(),
                          (elements_sets[connected_set]).begin(),
                          (elements_sets[connected_set]).end());
    }
    new_elements.emplace_back(u);
    elements_sets[dsu.Parent(u)] = new_elements;
  }
  array<vec<int, 1>, 2> vertices_parities;
  function<void(int, int, bool)> DFS = [&](int u, int parent, bool parity) {
    vertices_parities[parity].emplace_back(u);
    for (auto& v : neighbors_vertices[u]) {
      if (v == parent) {
        continue;
      }
      DFS(v, u, parity ^ 1);
    }
  };
  DFS(0, -1, 0);
  for (int parity = 0; parity < 2; ++parity) {
    if (static_cast<int>((vertices_parities[parity]).size()) &&
        Ask(vertices_parities[parity])) {
      int left_index = 1,
          right_index =
              static_cast<int>((vertices_parities[parity]).size()) - 1;
      while (left_index < right_index) {
        int middle_index = (left_index + right_index) >> 1;
        vec<int, 1> vertices;
        for (int i = 0; i <= middle_index; ++i) {
          vertices.emplace_back(vertices_parities[parity][i]);
        }
        if (Ask(vertices)) {
          right_index = middle_index;
        } else {
          left_index = middle_index + 1;
        }
      }
      int index_1 = left_index;
      left_index = 0, right_index = index_1 - 1;
      while (left_index < right_index) {
        int middle_index = (left_index + right_index + 1) >> 1;
        vec<int, 1> vertices;
        for (int i = middle_index; i <= index_1; ++i) {
          vertices.emplace_back(vertices_parities[parity][i]);
        }
        if (Ask(vertices)) {
          left_index = middle_index;
        } else {
          right_index = middle_index - 1;
        }
      }
      int index_2 = left_index;
      vec<int, 1> parents(n_vertices, -1);
      queue<int> q;
      q.emplace(vertices_parities[parity][index_1]);
      while (static_cast<int>((q).size())) {
        int u = q.front();
        q.pop();
        for (auto& v : neighbors_vertices[u]) {
          if (v == parents[u]) {
            continue;
          }
          parents[v] = u;
          q.emplace(v);
        }
      }
      vec<int, 1> answer;
      for (int u = vertices_parities[parity][index_2]; ~u; u = parents[u]) {
        answer.emplace_back(u);
      }
      cout << "N " << static_cast<int>((answer).size()) << endl;
      for (auto& u : answer) {
        cout << u + 1 << ' ';
      }
      cout << endl;
      return 0;
    }
  }
  cout << "Y " << static_cast<int>((vertices_parities[0]).size()) << endl;
  for (auto& u : vertices_parities[0]) {
    cout << u + 1 << ' ';
  }
  cout << endl;
  return 0;
}
