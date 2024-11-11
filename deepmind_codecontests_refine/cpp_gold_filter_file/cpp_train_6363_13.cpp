#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  bool operator<(const node &rhs) const {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
};
node a[10];
vector<node> ans;
set<node> mp;
int main() {
  for (int i = 1; i <= 3; i++) {
    scanf("%d %d", &a[i].x, &a[i].y);
  }
  sort(a + 1, a + 4);
  int p = a[1].x;
  int q = a[1].y;
  for (int i = p; i <= a[2].x; i++) {
    node t;
    t.x = i;
    t.y = q;
    mp.insert(t);
    ans.push_back(t);
  }
  p = a[2].x;
  if (q >= a[2].y) {
    for (int j = q - 1; j >= a[2].y; j--) {
      node t;
      t.x = p;
      t.y = j;
      ans.push_back(t);
      mp.insert(t);
      if (abs(q - a[3].y) > abs(j - a[3].y)) {
        q = j;
      }
    }
  } else {
    for (int j = q + 1; j <= a[2].y; j++) {
      node t;
      t.x = p;
      t.y = j;
      if (mp.find(t) != mp.end()) continue;
      mp.insert(t);
      ans.push_back(t);
      if (abs(q - a[3].y) > abs(j - a[3].y)) {
        q = j;
      }
    }
  }
  for (int i = p + 1; i <= a[3].x; i++) {
    node t;
    t.x = i;
    t.y = q;
    ans.push_back(t);
  }
  p = a[3].x;
  if (q >= a[3].y) {
    for (int j = q - 1; j >= a[3].y; j--) {
      node t;
      t.x = p;
      t.y = j;
      if (mp.find(t) != mp.end()) continue;
      mp.insert(t);
      ans.push_back(t);
    }
  } else {
    for (int j = q + 1; j <= a[3].y; j++) {
      node t;
      t.x = p;
      t.y = j;
      if (mp.find(t) != mp.end()) continue;
      mp.insert(t);
      ans.push_back(t);
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].x, ans[i].y);
  }
  return 0;
}
