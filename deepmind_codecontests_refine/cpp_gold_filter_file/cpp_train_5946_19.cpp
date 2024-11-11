#include <bits/stdc++.h>
using namespace std;
struct Q {
  int a, b, w;
} q[300010];
bool operator<(Q a, Q b) { return a.b < b.b; }
long long ans[301000], w[301000], s[301000];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) cin >> q[i].a >> q[i].b, q[i].a--, q[i].w = i;
  sort(q, q + m);
  int Lim = (int)sqrt(n);
  for (int i = 0; i < m; i++) {
    if (q[i].b > Lim) {
      long long tmp = 0;
      for (int j = q[i].a; j < n; j += q[i].b) {
        tmp += w[j];
      }
      ans[q[i].w] = tmp;
    } else {
      memset(s, 0, sizeof(s));
      for (int j = n - 1; j >= 0; j--) s[j] = w[j] + s[j + q[i].b];
      int j = i;
      do {
        ans[q[j].w] = s[q[j].a];
        j++;
      } while (q[j].b == q[j - 1].b);
      i = j - 1;
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
