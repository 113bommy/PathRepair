#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
struct data {
  int w, id;
  data() {}
  data(int _w, int _id) : w(_w), id(_id) {}
  bool friend operator<(const data &a, const data &b) { return a.w > b.w; }
} a[maxn];
vector<int> v;
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].w);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    v.push_back(a[i].id * 2 - 1);
    if (i > 1) ans.push_back(make_pair(a[i].id * 2 - 1, a[i - 1].id * 2 - 1));
  }
  for (int i = 1; i <= n; ++i) {
    int d = i + a[i].w - 2;
    if (d < (int)v.size() - 1)
      ans.push_back(make_pair(v[d], a[i].id * 2));
    else {
      ans.push_back(make_pair(*v.rbegin(), a[i].id * 2));
      v.push_back(a[i].id * 2);
    }
  }
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
  return 0;
}
