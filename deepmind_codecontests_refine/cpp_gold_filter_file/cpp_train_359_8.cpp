#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y, id;
  bool operator<(const pt& a) const { return x < a.x || x == a.x && y < a.y; }
  bool operator==(const pt& a) const { return y == a.y && x == a.x; }
};
const int N = 200005;
vector<int> ids[N];
int ans[N], asz = 0;
bool ok[N];
vector<pt> v, up;
pt arr[N];
bool cwe(pt& a, pt& b, pt& c) {
  return 1ll * a.y * b.x * c.x * (c.y - b.y) +
             1ll * a.x * b.y * c.x * (a.y - c.y) +
             1ll * a.x * b.x * c.y * (b.y - a.y) <=
         0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &arr[i].x, &arr[i].y);
    arr[i].id = i;
  }
  sort(arr, arr + n);
  v.push_back(arr[0]);
  for (int i = 1; i < n; ++i) {
    while (v.size() &&
           (v[v.size() - 1].y < arr[i].y ||
            v[v.size() - 1].y == arr[i].y && v[v.size() - 1].x < arr[i].x))
      v.pop_back();
    if (v.size() && v[v.size() - 1] == arr[i])
      ids[v[v.size() - 1].id].push_back(arr[i].id);
    else
      v.push_back(arr[i]);
  }
  for (int i = 0; i < v.size(); ++i) {
    while (up.size() > 1 && !cwe(up[up.size() - 2], up[up.size() - 1], v[i]))
      up.pop_back();
    up.push_back(v[i]);
  }
  for (int i = 0; i < up.size(); ++i) {
    ans[asz++] = up[i].id;
    for (int j = 0; j < ids[up[i].id].size(); ++j)
      ans[asz++] = ids[up[i].id][j];
  }
  sort(ans, ans + asz);
  for (int i = 0; i < asz; ++i) printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}
