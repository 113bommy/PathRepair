#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
const int maxm = 100000 + 5;
int n, m, s;
int a[maxm];
int b[maxn], c[maxn];
int correct[maxm];
int a_pos[maxm], b_pos[maxn];
bool cmp_a(int i, int j) { return a[i] > a[j]; }
bool cmp_b(int i, int j) { return b[i] > b[j]; }
struct Node {
  int pass, pos;
  bool operator<(const Node& b) const { return pass > b.pass; }
};
bool ok(int days) {
  long long tot_pass = 0;
  priority_queue<Node> pq;
  int bi = 0;
  int cor[maxm];
  for (int ai = 0; ai < m;) {
    while (bi < n && b[b_pos[bi]] >= a[a_pos[ai]]) {
      pq.push((Node){c[b_pos[bi]], b_pos[bi]});
      bi++;
    }
    if (pq.empty()) return false;
    Node best = pq.top();
    tot_pass += best.pass;
    if (tot_pass > s) return false;
    pq.pop();
    for (int i = ai; i < min(ai + days, m); i++) cor[a_pos[i]] = best.pos + 1;
    ai += days;
  }
  for (int i = 0; i < m; i++) correct[i] = cor[i];
  return true;
}
int main(int argc, char* argv[]) {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) a_pos[i] = i;
  for (int i = 0; i < n; i++) b_pos[i] = i;
  sort(a_pos, a_pos + m, cmp_a);
  sort(b_pos, b_pos + n, cmp_b);
  int ans = -1;
  int L = 1, R = m;
  while (L <= R) {
    int M = L + (R - L) / 2;
    if (ok(M)) {
      ans = M;
      R = M - 1;
    } else
      L = M + 1;
  }
  if (ans < 0)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < m; i++) printf("%d ", correct[i]);
    printf("\n");
  }
  return 0;
}
