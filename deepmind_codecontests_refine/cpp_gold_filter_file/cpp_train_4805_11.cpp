#include <bits/stdc++.h>
using namespace std;
int n, q;
string second;
struct Bruh {
  int curd;
  int a;
  int b;
  int ab;
  int bc;
  int abc;
};
void op(Bruh x) {
  cout << x.curd << " " << x.a << " " << x.b << " " << x.ab << " " << x.bc
       << " " << x.abc << "\n";
}
Bruh tree[100005 * 6];
Bruh merge(Bruh a, Bruh b) {
  Bruh ans;
  ans.curd = a.curd + b.curd;
  ans.a = max(a.a, a.curd + b.a);
  ans.b = max(a.b, a.curd * -2 + b.b);
  ans.ab = max(max(a.ab, b.ab - a.curd), a.a + b.b - 2 * a.curd);
  ans.bc = max(max(a.bc, b.bc - a.curd), a.b + b.a + a.curd);
  ans.abc =
      max(max(a.abc, b.abc), max(a.a + b.bc - a.curd, a.ab + b.a + a.curd));
  return ans;
}
void upd(int node, int a, int b, int i, int j, int val) {
  if (a > b || a > j || b < i) return;
  if (a == b) {
    tree[node].curd = tree[node].a = val;
    tree[node].b = val * -2;
    tree[node].ab = tree[node].bc = -val;
    tree[node].abc = 0;
    return;
  }
  upd(node * 2, a, (a + b) / 2, i, j, val);
  upd(node * 2 + 1, 1 + (a + b) / 2, b, i, j, val);
  tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
void ret(int node, int a, int b) {
  cout << node << " " << a << " " << b << " ";
  op(tree[node]);
  if (a != b) {
    ret(node * 2, a, (a + b) / 2);
    ret(node * 2 + 1, 1 + (a + b) / 2, b);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  cin >> second;
  for (int i = (1); i <= (signed)(2 * n - 2); i++) {
    if (second[i - 1] == '(') {
      upd(1, 1, 2 * n - 2, i, i, 1);
    } else {
      upd(1, 1, 2 * n - 2, i, i, -1);
    }
  }
  cout << tree[1].abc << "\n";
  for (int _ = 0; _ < (signed)(q); _++) {
    int x, y;
    cin >> x >> y;
    if (second[y - 1] == '(') {
      upd(1, 1, 2 * n - 2, x, x, 1);
    } else {
      upd(1, 1, 2 * n - 2, x, x, -1);
    }
    if (second[x - 1] == '(') {
      upd(1, 1, 2 * n - 2, y, y, 1);
    } else {
      upd(1, 1, 2 * n - 2, y, y, -1);
    }
    swap(second[x - 1], second[y - 1]);
    cout << tree[1].abc << "\n";
  }
  return 0;
}
