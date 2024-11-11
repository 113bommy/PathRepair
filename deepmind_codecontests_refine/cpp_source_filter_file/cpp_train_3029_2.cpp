#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
struct K {
  int col, len;
  K(int _c = 0, int _l = 0) { col = _c, len = _l; }
  bool operator==(const K &b) const { return col == b.col; }
};
struct ANS {
  int l, r;
  ANS(int _l = 0, int _r = 0) { l = _l, r = _r; }
} a[MAXN];
int acnt;
deque<K> Ks[4];
char s[4][MAXN];
int slen[4];
void cal(int id) {
  int last = 0, lcol = s[id][0] - 'a';
  for (int i = 1; i < slen[id]; i++) {
    if (s[id][i] != s[id][i - 1]) {
      Ks[id].push_back(K(lcol, i - last));
      last = i, lcol = s[id][i] - 'a';
    }
  }
  Ks[id].push_back(K(lcol, slen[id] - last));
}
deque<K> tmp[4];
void change(int l, int r) {
  for (int i = 0; i < l; i++) {
    a[acnt].l += Ks[0].front().len;
    tmp[0].push_back(Ks[0].front());
    Ks[0].pop_front();
  }
  for (int i = 0; i < r; i++) {
    a[acnt].r += Ks[1].front().len;
    tmp[1].push_back(Ks[1].front());
    Ks[1].pop_front();
  }
  acnt++;
  while (!tmp[0].empty()) {
    if (!Ks[1].empty() && tmp[0].back() == Ks[1].front())
      Ks[1].front().len += tmp[0].back().len;
    else
      Ks[1].push_front(tmp[0].back());
    tmp[0].pop_back();
  }
  while (!tmp[1].empty()) {
    if (!Ks[0].empty() && tmp[1].back() == Ks[0].front())
      Ks[0].front().len += tmp[1].back().len;
    else
      Ks[0].push_front(tmp[1].back());
    tmp[1].pop_back();
  }
}
int main() {
  for (int i = 0; i < 2; i++) {
    scanf("%s", s[i]);
    slen[i] = strlen(s[i]);
    cal(i);
  }
  while (1) {
    if (Ks[0].size() == 1 && Ks[1].size() == 1) break;
    if (Ks[0].size() == 1) {
      if (Ks[1].size() <= 3) {
        if (Ks[1].front() == Ks[0].front())
          change(0, 1);
        else
          change(1, 1);
      } else {
        if (Ks[1].front() == Ks[0].front())
          change(0, 3);
        else
          change(0, 2);
      }
    } else if (Ks[1].size() == 1) {
      if (Ks[0].size() <= 3) {
        if (Ks[1].front() == Ks[0].front())
          change(1, 0);
        else
          change(1, 1);
      } else {
        if (Ks[1].front() == Ks[0].front())
          change(3, 0);
        else
          change(2, 0);
      }
    } else if (Ks[0].size() == 2) {
      if (Ks[1].size() <= 3) {
        if (Ks[0].front() == Ks[1].front())
          change(0, 1);
        else
          change(1, 1);
      } else {
        if (Ks[0].front() == Ks[1].front())
          change(1, 2);
        else
          change(1, 3);
      }
    } else if (Ks[1].size() == 2) {
      if (Ks[0].size() <= 3) {
        if (Ks[0].front() == Ks[1].front())
          change(1, 0);
        else
          change(1, 1);
      } else {
        if (Ks[0].front() == Ks[1].front())
          change(2, 1);
        else
          change(3, 1);
      }
    } else {
      if (Ks[0].front() == Ks[1].front()) {
        if (Ks[0].size() > Ks[1].size())
          change(1, 0);
        else
          change(0, 1);
      } else
        change(1, 1);
    }
  }
  printf("%d\n", acnt);
  for (int i = 0; i < acnt; i++) printf("%d %d\n", a[i].l, a[i].r);
  return 0;
}
