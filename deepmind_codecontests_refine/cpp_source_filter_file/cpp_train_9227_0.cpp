#include <bits/stdc++.h>
const int N = 3e5 + 10;
int n, s, t;
bool swp = false;
std::pair<int, int> c[N];
bool solve() {
  static int ans1, ans2;
  for (ans1 = 0; ans1 < n; ans1++)
    if ((ans1 + 1) * c[ans1].first >= s) break;
  if (ans1 == n) return false;
  for (ans2 = ans1 + 1; ans2 < n; ans2++)
    if ((ans2 - ans1) * c[ans2].first >= t) break;
  if (ans2 == n) return false;
  puts("Yes");
  if (swp) {
    printf("%d %d\n", ans2 - ans1, ans1 + 1);
    for (int i = ans1 + 1; i <= ans2; i++) printf("%d ", c[i].second + 1);
    putchar('\n');
    for (int i = 0; i <= ans1; i++) printf("%d ", c[i].second + 1);
    putchar('\n');
  } else {
    printf("%d %d\n", ans1 + 1, ans2 - ans1);
    for (int i = 0; i <= ans1; i++) printf("%d ", c[i].second + 1);
    putchar('\n');
    for (int i = ans1 + 1; i <= ans2; i++) printf("%d ", c[i].second + 1);
    putchar('\n');
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &s, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i].first);
    c[i].second = i;
  }
  std::sort(c, c + n, [](std::pair<int, int> a, std::pair<int, int> b) {
    return a.first > b.first;
  });
  if (!solve()) {
    std::swap(s, t);
    swp = true;
    if (!solve()) puts("NO");
  }
  return 0;
}
