#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
typedef struct item* pitem;
struct item {
  int prior, cnt, key;
  long long summ;
  pitem l, r;
  item(int key = 0, int prior = 0) : key(key), prior(prior), l(NULL), r(NULL) {
    cnt = 1;
    summ = key;
  }
};
int cnt(pitem it) { return it ? it->cnt : 0; }
long long summ(pitem it) { return it ? it->summ : 0; }
void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
    it->summ = summ(it->l) + summ(it->r) + it->key;
  }
}
void merge(pitem& t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  upd_cnt(t);
}
void split(pitem t, int key, pitem& l, pitem& r) {
  if (!t)
    l = r = NULL;
  else if (key <= t->key)
    split(t->l, key, l, t->l), r = t;
  else
    split(t->r, key, t->r, r), l = t;
  upd_cnt(t);
}
int n;
item items[111000];
int rands[111000];
int main() {
  char buf[1024];
  gets(buf);
  sscanf(buf, "%d", &n);
  pitem root[5];
  memset(root, 0, sizeof root);
  ;
  for (int i = 0, _n = (n); i < _n; i++) rands[i] = i;
  random_shuffle(rands, rands + n);
  for (int step = 0, _n = (n); step < _n; step++) {
    gets(buf);
    char cmd[1024];
    int val;
    sscanf(buf, "%s %d", cmd, &val);
    if (strcmp(cmd, "sum") == 0) {
      cout << summ(root[2]) << "\n";
    } else {
      pitem ends[5];
      for (int i = 0, _n = (5); i < _n; i++)
        split(root[i], val, root[i], ends[i]);
      if (strcmp(cmd, "add") == 0) {
        int mn = 0x7fffffff;
        for (int i = 0, _n = (5); i < _n; i++) mn = min(cnt(root[i]), mn);
        for (int i = 0, _n = (5); i < _n; i++)
          if (cnt(root[i]) == mn) {
            items[step] = item(val, rands[step]);
            merge(root[i], root[i], &items[step]);
            break;
          }
        for (int i = 0, _n = (5); i < _n; i++)
          merge(root[i], root[i], ends[(i + 4) % 5]);
      } else {
        for (int i = 0, _n = (5); i < _n; i++) {
          pitem dummy;
          split(ends[i], val + 1, dummy, ends[i]);
        }
        for (int i = 0, _n = (5); i < _n; i++)
          merge(root[i], root[i], ends[(i + 1) % 5]);
      }
    }
  }
  return 0;
}
