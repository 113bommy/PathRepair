#include <bits/stdc++.h>
using namespace std;
struct fenwick {
  map<unsigned long, map<unsigned int, char>> bit;
  void add(unsigned long i, int val, int upd) {
    while (i < 1000000001LL) {
      bit[i][val] += upd;
      i += (i & -i);
    }
  }
  int sum(unsigned long i, int n) {
    int val = 0;
    while (i > 0) {
      val += bit[i][n];
      i -= (i & -i);
    }
    return val;
  }
};
vector<int> v;
void call() {
  int q;
  cin >> q;
  fenwick tree;
  while (q--) {
    int a, c;
    long b;
    cin >> a >> b >> c;
    if (a == 1) {
      tree.add(b, c, 1);
    } else if (a == 2) {
      tree.add(b, c, -1);
    } else if (a == 3) {
      v.push_back(tree.sum(b, c));
    }
  }
}
int main() {
  call();
  for (auto x : v) cout << x << '\n';
}
