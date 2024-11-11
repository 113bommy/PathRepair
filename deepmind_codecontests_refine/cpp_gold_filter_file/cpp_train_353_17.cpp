#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, num, ans;
pair<int, pair<int, int> > a[N * 3];
pair<int, pair<int, int> > b[N * 3];
set<pair<int, int> > S1;
multiset<int> S2;
int main() {
  scanf("%d", &n);
  for (int j = 1; j <= 3; j++)
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      a[++num] = make_pair(x, make_pair(j, i));
    }
  sort(a + 1, a + 1 + n * 3);
  num = 0;
  for (int i = 1; i <= n * 3;) {
    int j = i, k1 = n * 3 + 1, k2 = n * 3 + 1, k3 = n * 3 + 1;
    while (a[j].first == a[i].first && j <= n * 3) {
      int x = a[j].second.first, y = a[j].second.second;
      if (x == 1) k1 = min(k1, y);
      if (x == 2) k2 = min(k2, y);
      if (x == 3) k3 = min(k3, y);
      j++;
    }
    b[++num] = make_pair(k1, make_pair(k2, k3));
    i = j;
  }
  sort(b + 1, b + 1 + num);
  ans = n * 3;
  S1.insert(make_pair(0, 0));
  S2.insert(0);
  for (int i = num; i >= 1; i--) {
    int now = b[i].first + (*S2.begin());
    ans = min(ans, now);
    int x = b[i].second.first, y = b[i].second.second;
    pair<int, int> k1 = make_pair(-1, -1), k2 = make_pair(-1, -1);
    while (1) {
      set<pair<int, int> >::iterator it = S1.upper_bound(make_pair(x, y));
      if (it == S1.begin()) break;
      it--;
      if ((*it).second > y) break;
      S1.erase(it);
      S2.erase(S2.find((*it).first + (*it).second));
      if (k2.first == -1) k2 = make_pair(x, (*it).second);
      k1 = make_pair((*it).first, y);
    }
    if (k1.first != -1) S1.insert(k1), S2.insert(k1.first + k1.second);
    if (k2.first != -1) S1.insert(k2), S2.insert(k2.first + k2.second);
  }
  ans = min(ans, (*S2.begin()));
  printf("%d\n", ans);
  return 0;
}
