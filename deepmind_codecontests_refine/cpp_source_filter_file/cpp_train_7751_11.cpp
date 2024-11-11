#include <bits/stdc++.h>
using namespace std;
int in() {
  int a;
  scanf("%d", &a);
  return a;
}
long long inll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
double ind() {
  double a;
  scanf("%lf", &a);
  return a;
}
long double inld() {
  long double a;
  scanf("%Lf", &a);
  return a;
}
const long double PI = acosl(-1);
const long double EPS = 1e-9;
const int INF = 100000008;
const int e4 = 10004;
const int e5 = 100005;
const int e6 = 1000006;
const int e7 = 10000007;
int tree[1 << 18], frq[e5];
set<pair<int, int> > mySet;
pair<int, int> a[e5];
int _get(int l, int r) {
  l += 1 << 17;
  r += 1 << 17;
  int s = 0;
  while (l <= r) {
    if (l % 2 == 1) s = max(s, tree[l++]);
    if (r % 2 == 0) s = max(s, tree[r--]);
    l /= 2;
    r /= 2;
  }
  return s;
}
void _update(int idx, int val) {
  idx += 1 << 17;
  tree[idx] = val;
  for (idx /= 2; idx >= 1; idx /= 2) {
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
  }
}
int main() {
  int n = in(), lis = 0;
  for (int i = 0; i < n; ++i) {
    a[i].second = in();
    int t = _get(1, a[i].second - 1) + 1;
    a[i].first = t;
    _update(a[i].second, t);
    lis = max(lis, t);
  }
  set<pair<int, int> >::iterator p;
  bool foundLis = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].first == lis) {
      foundLis = 1;
      mySet.insert(a[i]);
      frq[lis]++;
      continue;
    }
    if (!foundLis) {
      a[i].first = 0;
      continue;
    }
    if (!mySet.empty()) {
      p = mySet.lower_bound({a[i].first + 2, 0});
      p--;
      if (p->first > a[i].first && p->second > a[i].second) {
        mySet.insert(a[i]);
        frq[a[i].first]++;
      } else {
        a[i].first = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (frq[a[i].first] == 0)
      printf("1");
    else if (frq[a[i].first] == 1)
      printf("3");
    else
      printf("2");
  }
  printf("\n");
}
