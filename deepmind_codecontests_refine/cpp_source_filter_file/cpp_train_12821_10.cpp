#include <bits/stdc++.h>
using namespace std;
struct mir {
  int x, y, xx, yy;
};
vector<mir> vec;
int n, a[1005], b[1005], to[1005], fro[1005];
int c_who[1005], r_who[1005], r_to[1005], r_fro[1005];
bool no_use(int x) { return (to[x] == c_who[x] && fro[x] == r_who[x]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    r_who[b[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    c_who[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) to[i] = fro[i] = r_to[i] = r_fro[i] = i;
  for (int i = 1; i < n; ++i) {
    if (no_use(i)) continue;
    vec.push_back((mir){i, r_to[c_who[i]], r_to[r_who[i]], i});
    int w = to[i];
    int ww = fro[i];
    swap(to[i], to[r_to[c_who[i]]]);
    swap(fro[i], fro[r_fro[r_who[i]]]);
    swap(r_to[c_who[i]], r_to[w]);
    swap(r_fro[r_who[i]], r_fro[ww]);
  }
  printf("%d\n", vec.size());
  for (int i = 0; i < vec.size(); ++i)
    printf("%d %d %d %d\n", vec[i].x, vec[i].y, vec[i].xx, vec[i].yy);
  return 0;
}
