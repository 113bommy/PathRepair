#include <bits/stdc++.h>
using namespace std;
template <class T, int order>
struct pa {
  static const int H = 1 << (order - 1);
  pa<T, order - 1>* left;
  pa<T, order - 1>* right;
  T total;
  pa(int)
      : left(new pa<T, order - 1>(0)),
        right(new pa<T, order - 1>(0)),
        total(0) {}
  pa() : left(nullptr), right(nullptr), total(0) {}
  int upper_bound(int x) {
    if (total == 0) {
      return -1;
    }
    if (x < H) {
      return left->upper_bound(x);
    } else {
      int p = right->upper_bound(x - H);
      if (p == -1) {
        return left->upper_bound(H - 1);
      } else {
        return p + H;
      }
    }
  }
  int lower_bound(int x) {
    if (total == 0) {
      return H;
    }
    if (x < H) {
      int p = left->lower_bound(x);
      if (p == H) {
        return H + right->lower_bound(x - H);
      } else {
        return p;
      }
    } else {
      return H + right->lower_bound(x - H);
    }
  }
  int closest(int x, int h) {
    if (total == 0) {
      return -1;
    }
    int r = lower_bound(x + h);
    int l = upper_bound(x);
    if (l == -1) {
      return r;
    }
    x = 2 * x + h;
    if (abs(2 * r - x) < abs(x - 2 * l)) {
      return r;
    }
    return l;
  }
  pa<T, order>* insert(int x) {
    pa<T, order>* tmp = new pa<T, order>(*this);
    if (x < H) {
      tmp->left = tmp->left->insert(x);
    } else {
      tmp->right = tmp->right->insert(x - H);
    }
    tmp->total = tmp->left->total + tmp->right->total;
    return tmp;
  }
  pa<T, order>* merge(pa<T, order>* arr) {
    if (arr->total == 0) {
      return this;
    }
    if (this->total == 0) {
      return arr;
    }
    pa<T, order>* z = this;
    pa<T, order>* w = arr;
    if (z->total < w->total) {
      swap(z, w);
    }
    pa<T, order>* tmp = new pa<T, order>(*z);
    tmp->left = tmp->left->merge(w->left);
    tmp->right = tmp->right->merge(w->right);
    return tmp;
  }
  void print(int offset = 0) {
    left->print(offset);
    right->print(offset + H);
  }
};
template <class T>
struct pa<T, 0> {
  T total;
  pa(int) : total(0) {}
  pa() : total(0) {}
  int upper_bound(int) {
    if (total == 0) {
      return -1;
    } else {
      return 0;
    }
  }
  int lower_bound(int) { return total ? 0 : 1; }
  pa<T, 0>* insert(int) {
    if (this->total != 0) {
      return this;
    }
    pa<T, 0>* tmp = new pa<T, 0>(*this);
    tmp->total = 1;
    return tmp;
  }
  pa<T, 0>* merge(pa<T, 0>* arr) {
    if (arr->total == 0 || this->total == 1) {
      return this;
    } else {
      return this->insert(0);
    }
  }
  void print(int offset = 0) {
    if (total != 0) {
      cerr << offset << ' ';
    }
  }
};
struct logical_union {
  pa<int, 17>* a;
  pa<int, 17>* b;
  int b_offset;
  int closest(int x, int h) {
    int u = a->closest(x, h);
    int v = b->closest(x + b_offset, h) - b_offset;
    if (u == -1) {
      return v;
    }
    x = 2 * x + h;
    if (abs(2 * u - x) < abs(2 * v - x)) {
      return u;
    }
    return v;
  }
};
int n, root;
vector<int> e[100005];
pa<int, 17> difolt(0);
pa<int, 17>* dole[100005];
pa<int, 17>* gore[100005];
pa<int, 17>* putt[100005];
int sz[100005];
int parent[100005];
void dfs1(int x) {
  sz[x] = 1;
  dole[x] = &difolt;
  for (int y : e[x]) {
    dfs1(y);
    dole[x] = dole[x]->merge(dole[y]);
    sz[x] += sz[y];
  }
  dole[x] = dole[x]->insert(sz[x]);
}
vector<pa<int, 17>*> prep_prefix[100005];
vector<pa<int, 17>*> prep_suffix[100005];
void prepuj(int x) {
  int chld = e[x].size();
  if (chld <= 1) {
    return;
  }
  auto& prep_prefix = ::prep_prefix[x];
  prep_prefix.resize(chld);
  auto& prep_suffix = ::prep_suffix[x];
  prep_suffix.resize(chld);
  prep_prefix[0] = dole[e[x][0]];
  prep_suffix[chld - 1] = dole[e[x][chld - 1]];
  for (int i = 1; i < chld; i++) {
    prep_prefix[i] = prep_prefix[i - 1]->merge(dole[e[x][i]]);
  }
  for (int i = chld - 2; i >= 0; i--) {
    prep_suffix[i] = prep_suffix[i + 1]->merge(dole[e[x][i]]);
  }
}
void dfs2(int x, int p, int i, int chld) {
  if (x == p) {
    int j = 0;
    prepuj(x);
    gore[x] = &difolt;
    for (int y : e[x]) {
      dfs2(y, x, j, e[x].size());
      j++;
    }
  } else {
    gore[x] = gore[p];
    if (chld > 1) {
      if (i > 0) {
        gore[x] = gore[x]->merge(prep_prefix[p][i - 1]);
      }
      if (i < chld - 1) {
        gore[x] = gore[x]->merge(prep_suffix[p][i + 1]);
      }
    }
    prepuj(x);
    int j = 0;
    for (int y : e[x]) {
      dfs2(y, x, j, e[x].size());
      j++;
    }
  }
}
void dfs3(int x, int p) {
  if (x == p) {
    putt[x] = &difolt;
  } else {
    putt[x] = putt[p]->insert(sz[x]);
  }
  for (int y : e[x]) {
    dfs3(y, x);
  }
}
void test() {
  pa<int, 17>* ig = &difolt;
  ig = ig->insert(6);
  ig = ig->insert(2);
  ig = ig->insert(5);
  ig = ig->insert(6);
  pa<int, 17>* iq = &difolt;
  iq = iq->insert(6);
  iq = iq->insert(8);
  iq = iq->insert(3);
  ig = ig->merge(iq);
  for (int i = 0; i <= 10; i++) {
    cerr << i << ' ' << ig->upper_bound(i) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    if (u == 0) {
      root = v;
    } else {
      e[u].push_back(v);
      parent[v] = u;
    }
  }
  dfs1(root);
  dfs2(root, root, 0, 0);
  dfs3(root, root);
  for (int x = 1; x <= n; x++) {
    if (e[x].size() == 0) {
      cout << n - 1 << '\n';
      continue;
    }
    if (x == root && e[x].size() == 1) {
      cout << n - 1 << '\n';
      continue;
    }
    int min_v = 1e9, min_x;
    int max_v = -99, max_x;
    int govno_v = -99;
    int br = 0;
    for (int y : e[x]) {
      br++;
      if (sz[y] < min_v) {
        min_v = sz[y];
        min_x = y;
      }
      if (sz[y] > max_v) {
        govno_v = max_v;
        max_v = sz[y];
        max_x = y;
      } else if (sz[y] > govno_v) {
        govno_v = sz[y];
      }
    }
    if (x != root) {
      br++;
      int szz = n - sz[x];
      if (szz < min_v) {
        min_v = szz;
        min_x = x;
      }
      if (szz > max_v) {
        govno_v = max_v;
        max_v = szz;
        max_x = x;
      } else if (szz > govno_v) {
        govno_v = szz;
      }
    }
    if (max_v == 1) {
      cout << "1\n";
      continue;
    }
    int xxx;
    int argg = (max_v - min_v) / 2;
    int modd = (max_v - min_v) % 2;
    if (max_x == x) {
      xxx = logical_union({gore[x], putt[x], sz[x]}).closest(argg, modd);
    } else {
      xxx = dole[max_x]->closest(argg, modd);
    }
    cout << max(max(min_v + xxx, max_v - xxx), govno_v) << '\n';
  }
}
