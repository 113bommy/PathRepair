#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, m, k, s;
vector<int> ap[maxn], can_erase;
int v[maxn];
int freq[maxn];
int quiero[maxn];
int last_idx[maxn];
bool solved[maxn];
int needed[maxn];
int main() {
  scanf("%d %d %d %d", &m, &k, &n, &s);
  for (int i = 1; i <= 500000; i++) ap[i].push_back(-1);
  for (int i = 0; i < m; i++) {
    scanf("%d", &v[i]);
    ap[v[i]].push_back(i);
  }
  for (int i = 0; i < s; i++) {
    scanf("%d", &quiero[i]);
    freq[quiero[i]]++;
  }
  for (int i = 0; i < s; i++) {
    int val = quiero[i];
    if (solved[val]) continue;
    solved[val] = true;
    int p = 0, cnt = 0;
    for (int j = 0; j < ap[val].size();) {
      if (ap[val][j] < p && (j + 1 == ap[val].size() || ap[val][j + 1] >= p)) {
        int next_idx = maxn;
        if (j + freq[val] < ap[val].size()) {
          next_idx = ap[val][j + freq[val]];
        }
        needed[cnt] = max(needed[cnt], next_idx);
        p += k;
        cnt++;
      } else
        j++;
      if (p >= m) break;
    }
  }
  for (int i = 0; (i + 1) * k < m; i++) {
    if (needed[i] == maxn) continue;
    if (m - (needed[i] - k * (i + 1) + 1) < k * n) continue;
    int filler = k - s;
    for (int j = k * i; j <= needed[i]; j++) {
      if (freq[v[j]] != 0) {
        freq[v[j]]--;
      } else if (filler > 0) {
        filler--;
      } else {
        can_erase.push_back(j + 1);
      }
    }
    printf("%d\n", can_erase.size());
    for (auto q : can_erase) printf("%d ", q);
    return 0;
  }
  printf("-1");
  return 0;
}
