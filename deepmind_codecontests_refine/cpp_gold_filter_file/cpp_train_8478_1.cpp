#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int nextValid[N], V[N], B[N], res[N], nextDist[N];
bool valid[N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  fill(nextDist + 1, nextDist + n + 1, 1);
  fill(valid + 1, valid + n + 1, true);
  for (int i = 1; i <= n; i++) scanf("%d", &nextValid[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &V[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
  vector<int> used;
  for (int i = 1; i <= m; i++) {
    int a = (V[i] + res[i - 1] - 1) % n + 1;
    while (B[i] > 0) {
      if (valid[a]) {
        used.push_back(a);
        valid[a] = false;
      }
      B[i] -= nextDist[a];
      if (a == nextValid[a]) break;
      a = nextValid[a];
    }
    res[i] = (int)used.size();
    while (!used.empty()) {
      a = used.back();
      used.pop_back();
      if (!valid[nextValid[a]]) {
        nextDist[a] += nextDist[nextValid[a]];
        nextValid[a] = nextValid[nextValid[a]];
      }
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
  return 0;
}
