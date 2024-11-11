#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long rt;
int A[N], LZ[N], n;
struct node {
  int mn = 0, t = 0;
} D[N << 2];
vector<int> mn, mx;
node merg(node& a, node& b) {
  node rt;
  rt.mn = min(a.mn, b.mn);
  if (rt.mn == a.mn) rt.t += a.t;
  if (rt.mn == b.mn) rt.t += b.t;
  return (rt);
}
void build(int id = 1, int l = 0, int r = n) {
  D[id].t = r - l;
  if (r - l < 2) return;
  int mid = ((l + r) >> 1);
  build((id << 1), l, mid);
  build((id << 1 | 1), mid, r);
}
void shift(int id, int l, int r) {
  D[(id << 1)].mn += LZ[id];
  D[(id << 1 | 1)].mn += LZ[id];
  LZ[(id << 1)] += LZ[id];
  LZ[(id << 1 | 1)] += LZ[id];
  LZ[id] = 0;
  return;
}
void add(int s, int e, int d, int id = 1, int l = 0, int r = n) {
  if (l >= e || r <= s) return;
  if (l >= s && r <= e) {
    D[id].mn += d;
    LZ[id] += d;
    return;
  }
  int mid = ((l + r) >> 1);
  shift(id, l, r);
  add(s, e, d, (id << 1), l, mid);
  add(s, e, d, (id << 1 | 1), mid, r);
  D[id] = merg(D[(id << 1)], D[(id << 1 | 1)]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    A[a] = b;
  }
  build();
  mx = mn = {-1};
  add(0, n, 1);
  for (int i = 0; i < n; i++) {
    while ((int)mx.size() > 1 && A[i] > A[mx.back()]) {
      add(mx[(int)mx.size() - 2] + 1, mx.back() + 1, A[i] - A[mx.back()]);
      mx.pop_back();
    }
    while ((int)mn.size() > 1 && A[i] < A[mn.back()]) {
      add(mn[(int)mn.size() - 2] + 1, mn.back() + 1, -A[i] + A[mn.back()]);
      mn.pop_back();
    }
    mx.push_back(i);
    mn.push_back(i);
    add(0, i + 1, -1);
    if (!D[1].mn) rt += D[1].t;
  }
  printf("%lld", rt);
}
