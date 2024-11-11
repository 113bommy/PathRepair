#include <bits/stdc++.h>
using namespace std;
struct ob {
  int x, y, k, id;
  ob(){};
  ob(int _x, int _y, int _k, int _id) {
    x = _x;
    y = _y;
    k = _k;
    id = _id;
  }
  bool operator<(ob const &T) const { return x < T.x; }
};
ob singer[100100];
ob song[100100];
int cnt[100100], res[100100];
int n, m;
void enter() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    song[i] = ob(a, b, 0, i);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int c, d, k;
    scanf("%d%d%d", &c, &d, &k);
    singer[i] = ob(c, d, k, i);
    cnt[i] = k;
  }
}
int main() {
  enter();
  sort(song + 1, song + n + 1);
  sort(singer + 1, singer + m + 1);
  set<pair<int, int> > S;
  int j = 0;
  bool found = 1;
  for (int i = 1; i <= n; i++) {
    while (singer[j + 1].x <= song[i].x && j < m) {
      S.insert(make_pair(singer[j + 1].y, singer[j + 1].id));
      j++;
    }
    if (S.empty()) {
      found = 0;
      break;
    }
    set<pair<int, int> >::iterator it = S.lower_bound(make_pair(song[i].y, -1));
    if (it == S.end()) {
      found = 0;
      break;
    }
    pair<int, int> tmp = *it;
    S.erase(it);
    res[song[i].id] = tmp.second;
    cnt[tmp.second]--;
    if (cnt[tmp.second]) S.insert(tmp);
  }
  if (found) {
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
  } else
    printf("NO");
}
