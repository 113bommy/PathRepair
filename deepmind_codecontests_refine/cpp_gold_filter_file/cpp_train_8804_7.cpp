#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 2e5 + 7;
int n, m, k, t;
vector<int> b;
struct Node {
  int in, out;
  long long h;
  Node() {}
  Node(int i, int o, long long _h) : in(i), out(o), h(_h) {}
} a[N];
bool operator<(const Node &a, const Node &b) {
  if (a.out == b.out) return a.in < b.in;
  return a.out < b.out;
}
long long fen[M];
void add(int i, long long v) {
  for (; i <= (int)b.size(); i += i & -i) fen[i] = max(fen[i], v);
}
long long get(int i) {
  long long res = 0;
  for (; i > 0; i -= i & -i) res = max(res, fen[i]);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%lld", &a[i].in, &a[i].out, &a[i].h);
    b.push_back(a[i].in), b.push_back(a[i].out);
  }
  sort(a + 1, a + n + 1);
  sort(b.begin(), b.end()),
      b.resize((int)(unique(b.begin(), b.end()) - b.begin()));
  for (int i = n; i > 0; i--) {
    k = (lower_bound(b.begin(), b.end(), a[i].out) - b.begin()) + 1;
    t = (lower_bound(b.begin(), b.end(), a[i].in) - b.begin()) + 1;
    add(t, get(k - 1) + a[i].h);
  }
  printf("%lld", get((int)b.size()));
  return 0;
}
