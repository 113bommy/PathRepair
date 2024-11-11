#include <bits/stdc++.h>
using namespace std;
long long h, q, L, R, pos, la;
struct node {
  long long l, r;
  bool operator<(const node &a) const {
    if (l != a.l) return l < a.l;
    return r < a.r;
  }
};
vector<node> v;
int main() {
  scanf("%d %d", &h, &q);
  L = 1ll << (h - 1);
  R = (1ll << h) - 1;
  while (q--) {
    long long l, r;
    int f, ans;
    scanf("%d", &f);
    cin >> l >> r;
    scanf("%d", &ans);
    for (int j = f; j < h; j++) l *= 2, r = r * 2 + 1;
    if (ans) {
      if (L <= l - 1) v.push_back((node){L, l - 1});
      if (r + 1 <= R) v.push_back((node){r + 1, R});
    } else
      v.push_back((node){l, r});
  }
  pos = L, la = -1;
  v.push_back((node){R + 1, R + 1});
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    long long x = v[i].l;
    long long y = v[i].r;
    if (x > pos) {
      if (x - pos == 1) {
        if (la == -1)
          la = pos;
        else {
          cout << "Data not sufficient!" << endl;
          return 0;
        }
      } else {
        cout << "Data not sufficient!" << endl;
        return 0;
      }
    }
    pos = max(pos, y + 1);
  }
  if (la == -1)
    cout << "Game cheated!" << endl;
  else
    cout << la << endl;
  return 0;
}
