#include <bits/stdc++.h>
using namespace std;
struct Operation {
  int type;
  union {
    struct {
      int l;
      int c;
    };
    int v;
  };
  long long length;
  Operation() {}
  Operation(long long len) : length(len) {}
};
bool op_comp_len(const Operation& a, const Operation& b) {
  return a.length < b.length;
}
int main() {
  int m;
  cin >> m;
  vector<Operation> ops(m);
  long long length = 0;
  for (int i = 0; i < m; ++i) {
    cin >> ops[i].type;
    if (ops[i].type == 1) {
      cin >> ops[i].v;
      length++;
    } else {
      cin >> ops[i].l >> ops[i].c;
      length += ops[i].l * ops[i].c;
    }
    ops[i].length = length;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int position;
    cin >> position;
    ;
    while (true) {
      vector<Operation>::iterator it =
          lower_bound(ops.begin(), ops.end(), Operation(position), op_comp_len);
      assert(it != ops.end());
      if (it->length == position && it->type == 1) {
        cout << it->v << " ";
        break;
      } else {
        assert(it != ops.begin());
        position -= (it - 1)->length;
        position = (position - 1) % it->l + 1;
      }
    }
  }
  return 0;
}
