#include <bits/stdc++.h>
using namespace std;
const int MX = 100000 + 10;
long long n, arr[MX];
struct node {
  long long bit_[3];
  node() { memset(bit_, 0, sizeof(bit_)); }
};
vector<node> tree;
void add(long long inode, long long ptr, long long num) {
  if (ptr < 0) return;
  long long q = (num >> ptr) & 1;
  if (tree[inode].bit_[q] == 0) {
    tree.push_back(node());
    tree[inode].bit_[q] = (int)tree.size() - 1;
  }
  add(tree[inode].bit_[q], ptr - 1, num);
}
long long find_fit(long long x) {
  int ptr = 45;
  long long nd = 0;
  long long sol = 0;
  while (ptr >= 0) {
    sol *= 2;
    long long q = !((x >> ptr) & 1);
    if (q == 1) {
      if (tree[nd].bit_[1] != 0) {
        nd = tree[nd].bit_[1];
        sol++;
      } else
        nd = tree[nd].bit_[0];
    } else {
      if (tree[nd].bit_[0] != 0)
        nd = tree[nd].bit_[0];
      else {
        nd = tree[nd].bit_[1];
        sol++;
      }
    }
    ptr--;
  }
  return sol;
}
int main() {
  tree.push_back(node());
  cin >> n;
  long long q = 0;
  add(0, 45, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    q ^= arr[i];
    add(0, 45, q);
  }
  q = 0;
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    q ^= arr[i];
    long long p = find_fit(q);
    ans = max(ans, p ^ q);
  }
  cout << ans << endl;
  return 0;
}
