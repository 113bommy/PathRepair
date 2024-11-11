#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
struct Tree {
  bool tp;
  int fa;
  deque<int> c[2];
  deque<int>::iterator pfa[2];
} tr[N << 1];
int n, root, top, answer, rem[N << 1], ans[N], q[N << 1];
int tp[N << 1], sum[N << 1], tot[N << 1];
char st[N][N];
inline void remain(int now) { rem[++top] = now; }
inline int getrem(void) {
  int now = rem[top--];
  tr[now].c[0].clear();
  ;
  tr[now].c[1].clear();
  ;
  return now;
}
inline void addsonbg(int now, int ch) {
  tr[ch].fa = now;
  tr[now].c[0].push_front(ch);
  tr[ch].pfa[0] = tr[now].c[0].begin();
  tr[now].c[1].push_back(ch);
  tr[ch].pfa[1] = tr[now].c[1].end() - 1;
}
inline void addsoned(int now, int ch) {
  tr[ch].fa = now;
  tr[now].c[0].push_back(ch);
  tr[ch].pfa[0] = tr[now].c[0].end() - 1;
  tr[now].c[1].push_front(ch);
  tr[ch].pfa[1] = tr[now].c[1].begin();
}
inline void changeson(int x, int y) {
  tp[y] = tp[x];
  tot[y] = tot[x];
  sum[y] = sum[x];
  tr[y].pfa[0] = tr[x].pfa[0];
  tr[y].pfa[1] = tr[x].pfa[1];
  if (tr[y].fa = tr[x].fa)
    *(tr[y].pfa[0]) = *(tr[y].pfa[1]) = y;
  else
    root = y;
}
inline void init(int n) {
  tr[root = n + 1].tp = 0;
  for (int i = (N << 1) - 1; i > root; --i) rem[++top] = i;
  for (int i = 1; i <= n; ++i) addsoned(root, i);
}
inline bool reduce(char *st) {
  memset(tp, -1, sizeof tp);
  memset(sum, 0, sizeof sum);
  memset(tot, 0, sizeof tot);
  int l, r, cnt = 0, now, ff;
  vector<int> ch[3];
  bool isroot;
  for (int i = 1; i <= n; ++i)
    if (tp[i] = (st[i] == '1')) sum[q[++cnt] = i] = 1;
  l = 1;
  r = cnt;
  for (int i = 1; i <= n; ++i)
    if (!tp[i]) q[++r] = i;
  for (; l <= r; ++l) {
    isroot = (sum[now = q[l]] == cnt);
    ff = tr[now].fa;
    if (tp[now] == 2) {
      ch[0].clear();
      ;
      ch[1].clear();
      ;
      ch[2].clear();
      ;
      if (!tr[now].tp) {
        for (deque<int>::iterator it = tr[now].c[0].begin();
             it != tr[now].c[0].end(); ++it)
          ch[tp[*it]].push_back(*it);
        tr[now].c[0].clear();
        ;
        tr[now].c[1].clear();
        ;
        if (ch[2].empty()) {
          if (!isroot && ch[0].size() > 1) {
            int tmp = getrem();
            for (vector<int>::iterator it = ch[0].begin(); it != ch[0].end();
                 ++it)
              addsoned(tmp, *it);
            tr[tmp].tp = 0;
            addsoned(now, tmp);
          } else
            for (vector<int>::iterator it = ch[0].begin(); it != ch[0].end();
                 ++it)
              addsoned(now, *it);
          if (ch[1].size() > 1) {
            int tmp = getrem();
            for (vector<int>::iterator it = ch[1].begin(); it != ch[1].end();
                 ++it)
              addsoned(tmp, *it);
            tr[tmp].tp = 0;
            addsoned(now, tmp);
          } else if (ch[1].size() == 1)
            addsoned(now, ch[1][0]);
        } else if (ch[2].size() == 1) {
          int p1 = ch[2][0];
          tr[p1].tp = 1;
          if (isroot) {
            if (ch[1].size() > 1) {
              int tmp = getrem();
              for (vector<int>::iterator it = ch[1].begin(); it != ch[1].end();
                   ++it)
                addsoned(tmp, *it);
              tr[tmp].tp = 0;
              addsoned(p1, tmp);
            } else if (ch[1].size() == 1)
              addsoned(p1, ch[1][0]);
            if (!ch[0].empty()) {
              for (vector<int>::iterator it = ch[0].begin(); it != ch[0].end();
                   ++it)
                addsoned(now, *it);
              addsoned(now, p1);
            } else
              changeson(now, p1), remain(now), now = p1;
          } else {
            if (ch[1].size() > 1) {
              int tmp = getrem();
              for (vector<int>::iterator it = ch[1].begin(); it != ch[1].end();
                   ++it)
                addsoned(tmp, *it);
              tr[tmp].tp = 0;
              addsoned(p1, tmp);
            } else if (ch[1].size() == 1)
              addsoned(p1, ch[1][0]);
            if (ch[0].size() > 1) {
              int tmp = getrem();
              for (vector<int>::iterator it = ch[0].begin(); it != ch[0].end();
                   ++it)
                addsoned(tmp, *it);
              tr[tmp].tp = 0;
              addsonbg(p1, tmp);
            } else if (ch[0].size() == 1)
              addsonbg(p1, ch[0][0]);
            changeson(now, p1);
            remain(now);
            now = p1;
          }
        } else {
          if (ch[2].size() > 2 || !isroot) return 1;
          int p1 = ch[2][0], p2 = ch[2][1], tmp = getrem();
          for (deque<int>::iterator it = tr[p1].c[0].begin();
               it != tr[p1].c[0].end(); ++it)
            addsoned(tmp, *it);
          if (ch[1].size() > 1) {
            int nd = getrem();
            for (vector<int>::iterator it = ch[1].begin(); it != ch[1].end();
                 ++it)
              addsoned(nd, *it);
            tr[nd].tp = 0;
            addsoned(tmp, nd);
          } else if (ch[1].size() == 1)
            addsoned(tmp, ch[1][0]);
          for (deque<int>::iterator it = tr[p2].c[1].begin();
               it != tr[p2].c[1].end(); ++it)
            addsoned(tmp, *it);
          remain(p1);
          remain(p2);
          tr[tmp].tp = 1;
          if (!ch[0].empty()) {
            for (vector<int>::iterator it = ch[0].begin(); it != ch[0].end();
                 ++it)
              addsoned(now, *it);
            addsoned(now, tmp);
          } else
            changeson(now, tmp), remain(now), now = tmp;
        }
      } else {
        deque<int>::iterator le, ri;
        for (le = tr[now].c[0].begin(); !tp[*le]; ++le)
          ;
        for (ri = le; ri != tr[now].c[0].end() - 1 && tp[*(ri + 1)] == 1; ++ri)
          ;
        if (ri != tr[now].c[0].end() - 1 && tp[*(ri + 1)] == 2) ++ri;
        for (deque<int>::iterator it = ri + 1; it != tr[now].c[0].end(); ++it)
          if (tp[*it]) return 1;
        int l = *le, r = *ri;
        bool lnkle, lnkri;
        lnkle = !(le != tr[now].c[0].begin() || tp[l] == 2);
        lnkri = !(ri != tr[now].c[0].end() - 1 || tp[r] == 2);
        if (!isroot && !lnkle && !lnkri) {
          if (le != ri ||
              (le != tr[now].c[0].begin() && ri != tr[now].c[0].end() - 1))
            return 1;
          if (le == tr[now].c[0].begin() && tp[l] == 2) goto flagr;
          if (ri == tr[now].c[0].end() - 1 && tp[r] == 2) goto flagl;
        }
        if (tp[l] == 2 && tp[r] == 2) {
          tr[l].tp = 1;
          if (le != ri)
            for (deque<int>::iterator it = le + 1; it != ri; ++it)
              addsoned(l, *it);
          for (deque<int>::iterator it = tr[r].c[1].begin();
               it != tr[r].c[1].end(); ++it)
            addsoned(l, *it);
          remain(r);
          for (deque<int>::iterator it = le; it != tr[now].c[0].begin(); --it)
            addsonbg(l, *(it - 1));
          for (deque<int>::iterator it = ri + 1; it != tr[now].c[0].end(); ++it)
            addsoned(l, *it);
          changeson(now, l);
          remain(now);
          now = l;
        } else if (tp[l] == 2) {
        flagl:;
          tr[l].tp = 1;
          for (deque<int>::iterator it = le; it != tr[now].c[0].begin(); --it)
            addsonbg(l, *(it - 1));
          for (deque<int>::iterator it = le + 1; it != tr[now].c[0].end(); ++it)
            addsoned(l, *it);
          changeson(now, l);
          remain(now);
          now = l;
        } else if (tp[r] == 2) {
        flagr:;
          tr[r].tp = 1;
          for (deque<int>::iterator it = ri + 1; it != tr[now].c[0].end(); ++it)
            addsonbg(r, *it);
          for (deque<int>::iterator it = ri; it != tr[now].c[0].begin(); --it)
            addsoned(r, *(it - 1));
          changeson(now, r);
          remain(now);
          now = r;
        } else {
          if (!isroot && ri != tr[now].c[0].end() - 1)
            swap(tr[now].c[0], tr[now].c[1]);
        }
      }
    }
    if (isroot) break;
    sum[ff] += sum[now];
    if (!~tp[ff])
      tp[ff] = tp[now];
    else if (tp[ff] != tp[now])
      tp[ff] = 2;
    if (++tot[ff] == tr[ff].c[0].size()) q[++r] = ff;
  }
  return 0;
}
inline void display(int now) {
  if (tr[now].c[0].empty()) {
    ans[++answer] = now;
    return;
  }
  for (deque<int>::iterator it = tr[now].c[0].begin(); it != tr[now].c[0].end();
       ++it)
    display(*it);
}
int main(int argc, char **argv) {
  scanf("%d", &n);
  init(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", st[i] + 1);
    if (reduce(st[i])) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  display(root);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) putchar(st[i][ans[j]]);
    puts("");
  }
  return 0;
}
