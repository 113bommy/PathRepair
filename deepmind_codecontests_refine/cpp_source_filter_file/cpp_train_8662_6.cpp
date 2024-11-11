#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
struct HeapNode {
  int l, r, pa;
  bool operator<(const HeapNode& b) const { return r - l + 1 > b.r - b.l + 1; }
};
priority_queue<HeapNode> pq;
int n, cnt[2];
int A[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cnt[0] = n / 2;
  cnt[1] = n / 2 + (n % 2 != 0);
  for (register int i = 1; i <= n; ++i) {
    cin >> A[i];
    if (A[i]) {
      if (A[i] & 1) {
        --cnt[1];
        A[i] = 1;
      } else {
        --cnt[0];
        A[i] = 0;
      }
    } else {
      A[i] = -1;
    }
  }
  for (register int i = 1; i <= n; ++i) {
    if (A[i] != -1) {
      int t = i + 1;
      while (t <= n && A[t] == -1) ++t;
      if (t <= n && A[i] == A[t]) pq.push((HeapNode){i, t, A[i]});
    }
  }
  while (!pq.empty()) {
    HeapNode u = pq.top();
    pq.pop();
    if (u.r - u.l - 1 <= cnt[u.pa]) {
      cnt[u.pa] -= u.r - u.l - 1;
      int t = u.l + 1;
      while (t < u.r) A[t] = u.pa, t++;
    }
  }
  for (register int i = 1; i <= n; ++i)
    if (A[i] != -1) {
      pq.push((HeapNode){0, i, A[i]});
      break;
    }
  for (register int i = n; i >= 1; ++i)
    if (A[i] != -1) {
      pq.push((HeapNode){i, n + 1, A[i]});
      break;
    }
  while (!pq.empty()) {
    HeapNode u = pq.top();
    pq.pop();
    if (u.r - u.l - 1 <= cnt[u.pa]) {
      cnt[u.pa] -= u.r - u.l - 1;
      int t = u.l + 1;
      while (t < u.r) A[t] = u.pa, t++;
    }
  }
  for (int op = 0; op < 2; ++op) {
    for (register int i = 1; i <= n; ++i)
      if (A[i] == op) {
        int t = i;
        while (t + 1 <= n && A[t + 1] == -1 && cnt[op] != 0) {
          --cnt[op];
          A[t + 1] = op;
          ++t;
        }
        t = i;
        while (t - 1 >= 1 && A[t - 1] == -1 && cnt[op] != 0) {
          --cnt[op];
          A[t - 1] = op;
          --t;
        }
      }
  }
  for (register int op = 0; op < 2; ++op)
    for (register int i = 1; i <= n; ++i) {
      if (A[i] == -1 && cnt[op]) {
        --cnt[op];
        A[i] = op;
      }
    }
  int ans = 0;
  for (register int i = 1; i < n; ++i)
    if (A[i] != A[i + 1]) ++ans;
  cout << ans << endl;
  return 0;
}
