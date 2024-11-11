#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n;
array<int, 2> a[N];
vector<int> v[N];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i][0]), a[i][1] = i;
  sort(a + 1, a + 1 + n), reverse(a + 1, a + 1 + n);
  deque<int> q;
  int ind = 0;
  for (int i = (1); i <= (a[1][0]); ++i) {
    q.push_back(++ind);
    v[a[1][1]].push_back(ind);
  }
  for (int i = (2); i <= (n); ++i) {
    int w = min(a[i][0] - 1,
                (((int)(q).size()) + a[i][0] - (i == n ? 3 : a[i + 1][0])) / 2);
    for (int j = (1); j <= (w - 1); ++j) {
      v[a[i][1]].push_back(q.back());
      q.pop_back();
    }
    v[a[i][1]].push_back(q.back());
    for (int j = (w + 1); j <= (a[i][0] - 1); ++j) {
      v[a[i][1]].push_back(++ind);
      q.push_back(ind);
    }
    v[a[i][1]].push_back(q.front());
    q.push_back(q.front());
    q.pop_front();
  }
  printf("%d\n", ind);
  for (int i = (1); i <= (n); ++i) {
    for (auto x : v[i]) printf("%d ", x);
    puts("");
  }
  return 0;
}
