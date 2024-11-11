#include <bits/stdc++.h>
using namespace std;
int q, n;
struct UDS {
  vector<int> parent;
  vector<int> size;
  UDS() {}
  UDS(int a) : parent(a), size(a) {
    for (int i(0); i < a; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int find_set(int a) {
    if (a == parent[a])
      return a;
    else
      return parent[a] = find_set(parent[a]);
  }
  void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
  void show() {
    for (int i(0); i < parent.size(); i++) {
      cout << size[parent[i]] << " ";
    }
    cout << endl;
  }
};
int main() {
  cin >> q;
  for (int j(0); j < q; j++) {
    cin >> n;
    UDS s(n);
    for (int i(0); i < n; i++) {
      int a;
      cin >> a;
      s.union_set(i, a - 1);
    }
    s.show();
  }
  return 0;
}
