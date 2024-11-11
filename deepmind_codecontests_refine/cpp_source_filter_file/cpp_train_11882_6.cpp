#include <bits/stdc++.h>
void dbg(const char* fmt, ...) {}
const int size = 100000;
std::pair<int, int> ar[size];
std::pair<int, int> val[size];
std::vector<std::pair<int, int> > ans;
std::map<std::pair<int, int>, int> pos;
void swap(int a, int b) {
  if (a == b) return;
  ans.push_back(std::pair<int, int>(a, b));
  std::swap(val[a], val[b]);
  pos[val[a]] = a;
  pos[val[b]] = b;
}
bool lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i].first);
    ar[i].second = i;
    val[i] = ar[i];
    pos.insert(std::make_pair(val[i], i));
  }
  bool bad = false;
  for (int i = 0; i < n - 1; i++)
    if (ar[i].first > ar[i + 1].first) bad = true;
  if (!bad) {
    printf("0\n");
    return 0;
  }
  std::sort(ar, ar + n);
  std::pair<int, int> good = std::pair<int, int>(-1, -1);
  int gp = -1;
  for (int i = 0; i < n; i++) {
    if (lucky(ar[i].first)) {
      good = ar[i];
      gp = i;
      break;
    }
  }
  if (good == std::pair<int, int>(-1, -1)) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < gp; i++) {
    swap(pos[good], i);
    swap(i, pos[ar[i]]);
  }
  for (int i = n - 1; i > gp; i--) {
    swap(pos[good], i);
    swap(i, pos[ar[i]]);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
