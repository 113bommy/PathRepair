#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
template <class T>
inline T BigMod(T Base, T power, T M = 1000000007) {
  if (power == 0) return 1;
  if (power & 1)
    return ((Base % M) * (BigMod(Base, power - 1, M) % M)) % M;
  else {
    T y = BigMod(Base, power / 2, M) % M;
    return (y * y) % M;
  }
}
template <class T>
inline T ModInv(T A, T M = 1000000007) {
  return BigMod(A, M - 2, M);
}
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int arr[100005];
int tree[4 * 100005][61];
void update(int node, int b, int e, int indx) {
  if (b > indx or indx > e) return;
  if (b == e) {
    for (int i = 0; i < 60; i++) tree[node][i] = 1 + (i % arr[indx] == 0);
    return;
  }
  int mid = (b + e) >> 1;
  int left = 2 * node;
  int right = left + 1;
  update(left, b, mid, indx);
  update(right, mid + 1, e, indx);
  for (int i = 0; i < 60; i++) {
    tree[node][i] = tree[left][i] + tree[right][(tree[left][i] + i) % 60];
  }
}
int query(int node, int b, int e, int l, int r, int t) {
  if (b > r or l > e) return 0;
  if (b >= l && e <= r) return tree[node][t];
  int mid = (b + e) >> 1;
  int left = 2 * node;
  int right = left + 1;
  int p1 = query(left, b, mid, l, r, t);
  int p2 = query(right, mid + 1, e, l, r, (p1 + t) % 60);
  return p1 + p2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    update(1, 1, n, i);
  }
  int q;
  cin >> q;
  while (q--) {
    char c;
    int l, r;
    cin >> c >> l >> r;
    if (c == 'A') {
      cout << query(1, 1, n, l, r - 1, 0) << "\n";
    } else {
      arr[l] = r;
      update(1, 1, n, l);
    }
  }
  return 0;
}
