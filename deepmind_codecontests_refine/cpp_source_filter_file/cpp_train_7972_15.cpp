#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int a, b, id;
  bool operator<(const node& tem) const { return a > tem.a; }
} vec[maxn];
bool used[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &vec[i].a);
  for (int i = 1; i <= n; i++) scanf("%d", &vec[i].b);
  for (int i = 1; i <= n; i++) vec[i].id = i;
  sort(vec + 1, vec + 1 + n);
  priority_queue<pair<int, int> > q;
  int pcou = 1, cnt = 0;
  for (int i = 1; i <= n / 2 + 1; i++) {
    while (pcou < n && pcou <= 2 * i) {
      q.push(pair<int, int>(vec[pcou].b, vec[pcou].id));
      ++pcou;
    }
    if (!q.empty()) {
      ++cnt;
      int id = q.top().second;
      q.pop();
      used[id] = 1;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    if (used[i]) printf("%d ", i);
  return 0;
}
