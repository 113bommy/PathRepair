#include <bits/stdc++.h>
using namespace std;
const int mn = 3005;
const int mod = 1e9 + 7;
int n, a, b;
struct node {
  int a, b;
} p[mn];
bool vis[mn];
set<pair<int, int> > inA, waitA, waitB;
vector<int> inB;
void fillA() {
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; i++) {
    v.push_back({p[i].a, i});
  }
  sort(v.begin(), v.end());
  for (int i = n - 1; i >= n - a; i--) {
    int id = v[i].second;
    inA.insert({p[id].b - p[id].a, id});
  }
  for (int i = 0; i < n - a; i++) {
    int id = v[i].second;
    waitA.insert({p[id].a, id});
    waitB.insert({p[id].b, id});
  }
}
void fillB() {
  for (int i = 1; i <= b; i++) {
    int c1 = 0, c2 = 0;
    if ((int)waitA.size() && (int)inA.size()) {
      c1 = inA.rbegin()->first + waitA.rbegin()->first;
    }
    if ((int)waitB.size()) {
      c2 = waitB.rbegin()->first;
    }
    if (c1 > c2) {
      auto u = inA.rbegin();
      int id1 = u->second;
      inA.erase(*u);
      auto v = waitA.rbegin();
      int id2 = v->second;
      waitA.erase(*v);
      waitB.erase({p[id2].b, id2});
      inB.push_back(id1);
      inA.insert({p[id2].b - p[id2].a, id2});
    } else {
      auto u = waitB.rbegin();
      int id = u->second;
      waitB.erase(*u);
      waitA.erase({p[id].a, id});
      inB.push_back(id);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].a);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
  fillA();
  fillB();
  int ans = 0;
  vector<int> A;
  for (auto &i : inA) ans += p[i.second].a, A.push_back(i.second);
  for (auto &i : inB) ans += p[i].b;
  printf("%d\n", ans);
  sort(A.begin(), A.end());
  sort(inB.begin(), inB.end());
  for (auto &i : A) printf("%d ", i);
  puts("");
  for (auto &i : inB) printf("%d ", i);
  puts("");
  return 0;
}
