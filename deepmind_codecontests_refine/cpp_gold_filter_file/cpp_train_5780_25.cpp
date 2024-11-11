#include <bits/stdc++.h>
using namespace std;
pair<int, int> in[100005], out[100005], sol[100005];
int main() {
  int w, b, n, m, j = 0, k = 0, c = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &w, &b);
    if (b == 1)
      in[j++] = make_pair(w, i);
    else
      out[k++] = make_pair(w, i);
  }
  sort(in, in + j);
  sort(out, out + k);
  for (int i = 0; i < j; i++) sol[in[i].second] = make_pair(i + 1, i + 2);
  for (int r = 1; r < n - 1; r++) {
    if (c == k) break;
    for (int s = 1; s <= r; s++) {
      if (c == k) break;
      if (out[c].first >= in[r].first) {
        sol[out[c].second] = make_pair(s, r + 2);
        c++;
      } else {
        printf("-1\n");
        return 0;
      }
    }
  }
  for (int i = 0; i < m; i++) printf("%d %d\n", sol[i].first, sol[i].second);
  return 0;
}
