#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 10;
int a[maxn], b[maxn];
int ans[maxn];
vector<int> vs;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= (n + m); i++) scanf("%d", a + i);
  for (int i = 1; i <= (n + m); i++) {
    scanf("%d", b + i);
    if (b[i] == 1) {
      vs.push_back(i);
    }
  }
  int len = vs.size();
  ans[0] += vs[0] - 1;
  if (len == 1) {
    printf("%d\n", n);
    return 0;
  }
  int cnt = 0;
  for (int i = vs[0]; i <= (n + m); i++) {
    if (cnt == len) {
      ans[cnt - 1] += (n + m) - i + 1;
      break;
    }
    if (b[i] == 0) {
      if (abs(a[vs[cnt - 1]] - a[i]) <= abs(a[vs[cnt]] - a[i])) {
        ans[cnt - 1]++;
      } else
        ans[cnt]++;
    } else {
      cnt++;
    }
  }
  for (int i = 0; i < len; i++) {
    printf("%d%c", ans[i], i == len ? '\n' : ' ');
  }
  return 0;
}
