#include <bits/stdc++.h>
using namespace std;
struct zh {
  int a, b;
};
vector<zh> p[200005];
int fa[200005];
long long qz[200005];
int ds[200005];
int sl[200005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d", &k);
    int i = 1;
    while (i <= 2 * k) {
      p[i].clear();
      ds[i] = 0;
      qz[i] = 0;
      sl[i] = 1;
      i++;
    }
    i = 1;
    while (i <= 2 * k - 1) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      p[x].push_back({y, z});
      p[y].push_back({x, z});
      i++;
    }
    i = 1;
    while (i <= 2 * k) {
      fa[i] = -1;
      i++;
    }
    fa[1] = 1;
    queue<int> a;
    a.push(1);
    while (!a.empty()) {
      int temp = a.front();
      a.pop();
      int i = 0;
      while (i < p[temp].size()) {
        if (fa[p[temp][i].a] == -1) {
          fa[p[temp][i].a] = temp;
          qz[p[temp][i].a] = p[temp][i].b;
          a.push(p[temp][i].a);
          ds[temp]++;
        }
        i++;
      }
    }
    i = 1;
    while (i <= 2 * k) {
      if (ds[i] == 0) a.push(i);
      i++;
    }
    long long mmin = 0;
    long long mmax = 0;
    while (!a.empty()) {
      int t = a.front();
      a.pop();
      sl[fa[t]] += sl[t];
      mmin = mmin + qz[t] * (sl[t] % 2);
      mmax = mmax + qz[t] * min(2 * k - sl[t], sl[t]);
      ds[fa[t]]--;
      if (ds[fa[t]] == 0) a.push(fa[t]);
    }
    cout << mmin << " " << mmax << endl;
  }
  return 0;
}
