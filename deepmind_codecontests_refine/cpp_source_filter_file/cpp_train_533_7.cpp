#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[300001];
int pos[300001];
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
vector<pair<int, int>> v;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int f = pos[i];
    if (f - i >= n / 2) {
      v.push_back({i, f});
      swap(p[i], p[f]);
      swap(pos[p[i]], pos[p[f]]);
    } else if (f == i)
      continue;
    else {
      if (f <= n / 2) {
        v.push_back({f, n});
        swap(p[f], p[n]);
        swap(pos[p[f]], pos[p[n]]);
        v.push_back({i, n});
        swap(p[i], p[n]);
        swap(pos[p[i]], pos[p[n]]);
      } else if (i <= n / 2 && f > n / 2) {
        v.push_back({1, f});
        swap(p[1], p[f]);
        swap(pos[p[1]], pos[p[f]]);
        v.push_back({1, n});
        swap(p[1], p[n]);
        swap(pos[p[1]], pos[p[n]]);
        v.push_back({i, n});
        swap(p[i], p[f]);
        swap(pos[p[i]], pos[p[f]]);
        v.push_back({1, f});
        swap(p[1], p[f]);
        swap(pos[p[1]], pos[p[f]]);
      } else {
        v.push_back({1, f});
        swap(p[1], p[f]);
        swap(pos[p[1]], pos[p[f]]);
        v.push_back({1, i});
        swap(p[1], p[i]);
        swap(pos[p[1]], pos[p[i]]);
        v.push_back({1, f});
        swap(p[1], p[f]);
        swap(pos[p[1]], pos[p[f]]);
      }
    }
  }
  printf("%d\n", v.size());
  for (auto i : v) printf("%d %d\n", i.first, i.second);
  return 0;
}
