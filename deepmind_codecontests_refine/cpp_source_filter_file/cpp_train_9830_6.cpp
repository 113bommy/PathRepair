#include <bits/stdc++.h>
using namespace std;
void HoH() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
struct H {
  int sum, left, right;
};
string s;
int summ[4000009], leftt[4000009], rightt[4000009];
void build(int node, int start, int en) {
  if (start >= en) return;
  if (en - start < 2) {
    if (s[start] == '(')
      leftt[node] = 1;
    else
      rightt[node] = 1;
  } else {
    int mid = (start + en) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid, en);
    int z = min(leftt[2 * node], rightt[(2 * node) + 1]);
    summ[node] = summ[2 * node] + summ[(2 * node) + 1] + z;
    leftt[node] = leftt[2 * node] + leftt[(2 * node) + 1] - z;
    rightt[node] = rightt[2 * node] + rightt[(2 * node) + 1] - z;
  }
}
H query(int node, int start, int en, int l, int r) {
  H f;
  if (r - 1 < start || en - 1 < l || start >= en) {
    f.left = 0;
    f.right = 0;
    f.sum = 0;
    return f;
  }
  if (l <= start && en <= r) {
    f.left = leftt[node];
    f.right = rightt[node];
    f.sum = summ[node];
    return f;
  }
  int mid = (start + en) / 2;
  H p1 = query(2 * node, start, mid, l, r);
  H p2 = query(2 * node + 1, mid + 1, en, l, r);
  int z = min(p1.left, p2.right);
  f.sum = p1.sum + p2.sum + z;
  f.left = p1.left + p2.left - z;
  f.right = p1.right + p2.right - z;
  return f;
}
int main() {
  HoH();
  cin >> s;
  build(1, 0, s.size());
  int x, y, q;
  H ans;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    ans = query(1, 0, s.size(), x - 1, y);
    cout << ans.sum * 2 << endl;
  }
  return 0;
}
