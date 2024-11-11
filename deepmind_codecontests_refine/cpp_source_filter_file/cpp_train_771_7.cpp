#include <bits/stdc++.h>
using namespace std;
int n, a[200005], head = 0, ans = 1;
long long gap;
vector<int> v;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (a[i] != -1) {
      if (v.empty()) {
        head = i;
      } else if (v.size() == 1) {
        gap = (a[i] - a[v[0]]) / (i - v[0]);
        int r = (a[i] - a[v[0]]) % (i - v[0]);
        if (r || a[v[0]] - head * gap <= 0) {
          head = 0;
          ++ans;
          v.clear();
        }
      } else {
        int j = v.back();
        int r = (a[i] - a[j]) % (i - j);
        int q = (a[i] - a[j]) / (i - j);
        if (r || q != gap || a[v[0]] - head * gap <= 0) {
          head = gap >= 0 ? 0 : max(0LL, i - j - (a[j] - gap - 1) / -gap + 1);
          ++ans;
          v.clear();
        }
      }
      v.push_back(i);
    }
  }
  if (v.size() >= 2) {
    int tail = n - 1 - v.back();
    if (a[v.back()] + tail * gap <= 0) ++ans;
  }
  printf("%d\n", ans);
}
