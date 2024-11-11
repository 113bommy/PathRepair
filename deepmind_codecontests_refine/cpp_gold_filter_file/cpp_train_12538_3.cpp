#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int notp[N], near[N], a[N], pos[N];
vector<pair<int, int> > ans;
inline void sw(int i, int j) {
  ans.push_back(make_pair(i, j));
  swap(pos[a[i]], pos[a[j]]);
  swap(a[i], a[j]);
}
int main() {
  for (int i = 2; i < N; ++i) {
    if (!notp[i]) {
      for (int j = i * 2; j < N; j += i) notp[j] = 1;
    }
  }
  int tmp = 1;
  for (int i = 1; i < N - 1; ++i) {
    if (!notp[i + 1]) tmp = i;
    near[i] = tmp;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    pos[--a[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    while (near[pos[i] - i]) sw(pos[i] - near[pos[i] - i], pos[i]);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
  return 0;
}
