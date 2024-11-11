#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, o, w;
  bool operator<(const node& x) const { return (a) > (x.a); }
} s[1000005];
int ans[100005];
int main() {
  int t, N, i, suma, sumo, sumac, sumoc, n, k, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    N = 2 * n - 1;
    for (i = 1; i <= N; i++) {
      scanf("%d%d", &s[i].a, &s[i].o);
      s[i].w = i;
    }
    sort(s + 1, s + 1 + N);
    k = 0;
    for (i = 1, j = 1; i < n; i++, j += 2) {
      if (s[j].o > s[j + 1].o) {
        ans[k++] = s[j].w;
      } else {
        ans[k++] = s[j + 1].w;
      }
    }
    ans[k++] = s[N].w;
    cout << "YES" << endl;
    for (i = 0; i < k; i++) {
      cout << ans[i];
      if (i < k - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
