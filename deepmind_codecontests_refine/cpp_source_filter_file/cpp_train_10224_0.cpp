#include <bits/stdc++.h>
using namespace std;
int A[(100000 + 4)], S[(100000 + 4)];
void add(int pos, int val) {
  while (pos < (100000 + 4)) {
    A[pos] += val;
    pos += ((pos) & (-(pos)));
  }
}
int sum(int x) {
  int Ans = 0;
  while (x) {
    Ans += A[x];
    x -= ((x) & (-(x)));
  }
  return Ans;
}
struct point {
  int pos, val;
  bool operator<(const point &b) const {
    return val == b.val ? pos < b.pos : val > b.val;
  }
} P[(100000 + 4)];
struct query {
  int cnt, pos, ans, id;
  bool operator<(const query &b) const { return cnt < b.cnt; }
} Q[(100000 + 4)];
bool cmp(query A, query B) { return A.id < B.id; }
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> P[i].val;
    S[i] = P[i].val;
    P[i].pos = i;
  }
  sort(P + 1, P + 1 + n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> Q[i].cnt >> Q[i].pos;
    Q[i].id = i;
  }
  sort(Q + 1, Q + 1 + n);
  int size = 0;
  for (register int i = 1; i <= m; ++i) {
    while (size < Q[i].cnt) {
      ++size;
      add(P[size].pos, 1);
    }
    int l = 0, r = n + 1, mid = 0;
    while (l < r) {
      mid = l + r >> 1;
      if (sum(mid) >= Q[i].pos)
        r = mid;
      else
        l = mid + 1;
    }
    Q[i].ans = S[r];
  }
  sort(Q + 1, Q + 1 + n, cmp);
  for (int i = 1; i <= m; ++i) cout << Q[i].ans << "\n";
  return 0;
}
