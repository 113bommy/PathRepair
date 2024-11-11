#include <bits/stdc++.h>
using namespace std;
const int N = 1000002;
int n, q, a[N], ans[N];
pair<pair<int, int>, int> Q[N];
long long cnt;
vector<int> xors;
bool have[N];
void add(int i) {
  if (have[a[i]]) {
    cnt = cnt * 2 % 1000000007;
    return;
  }
  int n = ((int)(xors).size());
  for (int j = 0; j <= n - 1; ++j) {
    int x = a[i] ^ xors[j];
    xors.push_back(x);
    have[x] = true;
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &Q[i].first.first, &Q[i].first.second);
    Q[i].second = i;
  }
  xors = {0};
  cnt = have[0] = 1;
  sort(Q + 1, Q + 1 + q);
  int j = 1;
  for (int i = 1; i <= q; ++i) {
    while (j <= Q[i].first.first) add(j++);
    ans[Q[i].second] = have[Q[i].first.second] * cnt;
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
}
