#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;
pair<int, int> a[300000];
pair<int, int> b[300000];
multiset<int> aa, bb;
int tree[1048576];
int val[300000];
int szz;
int find(int i, int l, int r, int le, int ri) {
  if (le > r || ri < l) return 0;
  if (le >= l && ri <= r) return tree[i];
  return max(find(i * 2, l, r, le, (le + ri) / 2),
             find(i * 2 + 1, l, r, (le + ri) / 2 + 1, ri));
}
void update(int i, int val) {
  i += szz;
  tree[i] += val;
  i /= 2;
  while (i) {
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    i /= 2;
  }
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    aa.clear();
    bb.clear();
    int n;
    scanf("%d", &n);
    szz = 1;
    while (szz < n) szz *= 2;
    memset(tree, 0, sizeof(int) * szz * 2);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i].first);
      aa.insert(a[i].first);
      a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i].first);
      bb.insert(b[i].first);
      b[i].second = i;
    }
    if (aa != bb) {
      printf("NO\n");
      continue;
    }
    sort(a, a + n, greater<pair<int, int> >());
    sort(b, b + n, greater<pair<int, int> >());
    int flag = 0;
    for (int i = 0; i < n; i++) {
      val[i] = find(1, 0, b[i].second, 0, szz - 1);
      update(b[i].second, a[i].second);
      if (val[i] > a[i].second) {
        printf("NO\n");
        flag = 1;
        break;
      }
    }
    if (!flag) printf("YES\n");
  }
}
