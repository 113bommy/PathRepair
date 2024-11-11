#include <bits/stdc++.h>
using namespace std;
int sum[1 << 22];
int v[1 << 20];
int a[1 << 20];
int find(int x, int l, int r, int rank) {
  if (l == r - 1) return l;
  int mid = l + r >> 1;
  if (rank <= sum[x * 2 + 1])
    return find(x * 2 + 1, l, mid, rank);
  else
    return find(x * 2 + 2, mid, r, rank - sum[x * 2 + 1]);
}
void update(int x) { sum[x] = sum[x * 2 + 1] + sum[x * 2 + 2]; }
void add(int x, int l, int r, int p, int c) {
  if (l == r - 1) {
    sum[x] += c;
    return;
  }
  int mid = l + r >> 1;
  if (p < mid)
    add(x * 2 + 1, l, mid, p, c);
  else
    add(x * 2 + 2, mid, r, p, c);
  update(x);
}
int main() {
  ios::sync_with_stdio(false);
  int q, n;
  cin >> q >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int qq = 0; qq < q; qq++) {
    int ope;
    cin >> ope;
    if (ope == -1) {
      for (int i = 0; i < n && a[i] <= sum[0]; i++) {
        int p = find(0, 0, q, a[i] - i);
        add(0, 0, q, p, -1);
      }
    } else {
      v[qq] = ope;
      add(0, 0, q, qq, 1);
    }
  }
  if (sum[0] == 0) {
    cout << "Poor stack!" << endl;
  } else {
    for (int i = 1; i <= sum[0]; i++) {
      int p = find(0, 0, q, i);
      cout << v[p];
    }
    cout << endl;
  }
  return 0;
}
