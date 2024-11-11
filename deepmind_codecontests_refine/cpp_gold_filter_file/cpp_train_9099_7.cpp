#include <bits/stdc++.h>
using namespace std;
const int MAXN = 7005;
struct modification {
  int _level, le, ri, x;
};
struct interval {
  int l, r;
};
int N, M;
modification p[MAXN];
interval s[MAXN];
vector<int> res;
bool intersect(int l1, int r1, int l2, int r2) {
  if (l1 <= l2 && l2 <= r1) return true;
  if (l2 <= l1 && l1 <= r2) return true;
  return false;
}
int GetRight(int x) {
  int pow = 1;
  int cnt = 0;
  while (pow <= x) {
    pow *= 2;
    cnt++;
  }
  int result = cnt + x;
  return result;
}
int GetLeft(int x) {
  if (x == 1) return 1;
  return (GetRight(x - 1) + 1);
}
bool been(int x) {
  for (int i = 0; i < res.size(); i++)
    if (res[i] == x) return true;
  return false;
}
int main() {
  cin >> N >> M;
  int Size = 0;
  for (int i = 1; i <= M; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      Size++;
      cin >> p[Size]._level >> p[Size].le >> p[Size].ri >> p[Size].x;
      continue;
    }
    int Level;
    cin >> Level;
    cin >> s[Level].l;
    s[Level].r = s[Level].l;
    res.clear();
    for (int i = Level + 1; i <= N; i++) {
      s[i].l = GetLeft(s[i - 1].l);
      s[i].r = GetRight(s[i - 1].r);
    }
    for (int i = 1; i <= Size; i++) {
      if (p[i]._level < Level) continue;
      if (intersect(s[p[i]._level].l, s[p[i]._level].r, p[i].le, p[i].ri) &&
          !been(p[i].x))
        res.push_back(p[i].x);
    }
    cout << res.size() << endl;
  }
  return 0;
}
