#include <bits/stdc++.h>
using namespace std;
long long a[(1 << 17 + 5)];
long long tree[4 * (1 << 17 + 5)];
long long p, b;
long long level;
void buildTree(long long left, long long right, long long index,
               long long lvl) {
  if (left == right) {
    tree[index] = a[left];
    return;
  }
  long long mid = (left + right) / 2;
  buildTree(left, mid, 2 * index, lvl + 1);
  buildTree(mid + 1, right, 2 * index + 1, lvl + 1);
  if (lvl % 2 != level)
    tree[index] = tree[index * 2] | tree[index * 2 + 1];
  else
    tree[index] = tree[2 * index] ^ tree[2 * index + 1];
}
void update(long long left, long long right, long long p, long long b,
            long long index, long long lvl) {
  if (p < left || p > right) return;
  if (left == right) {
    tree[index] = b;
    return;
  }
  long long mid = (left + right) / 2;
  update(left, mid, p, b, 2 * index, lvl + 1);
  update(mid + 1, right, p, b, 2 * index + 1, lvl + 1);
  if (lvl % 2 != level)
    tree[index] = tree[index * 2] | tree[index * 2 + 1];
  else
    tree[index] = tree[2 * index] ^ tree[2 * index + 1];
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= (1 << n); i++) cin >> a[i];
  level = (n - 1) % 2;
  buildTree(1, (1 << n), 1, 1);
  while (m--) {
    cin >> p >> b;
    update(1, (1 << n), p, b, 1, 1);
    cout << tree[1] << endl;
  }
}
