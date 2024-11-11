#include <bits/stdc++.h>
using namespace std;
struct SAMType {
  int parent, len;
  int degree;
  int nxt[26];
  void clear() {
    parent = len = degree = 0;
    memset(nxt, 0, sizeof(nxt));
  }
} sam[100005 << 1];
int str[100005];
char c;
int cntSam;
int last, cur, cloneQ;
int sa[100005], lastSA[100005];
int rk[100005], key[100005];
int cnt[100005];
int sparse[100005][20];
struct stType {
  int lp, rp;
  int leftRk, rightRk;
  long long cnt;
} st[100005 * 20];
int cntST;
int stPointer[100005 << 1];
int qhy[100005 << 1];
int closed, open;
long long ans[5];
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
void sam_extend(int c) {
  int i, j;
  cur = ++cntSam;
  sam[cur].len = sam[last].len + 1;
  for (i = last; i != 0 && sam[i].nxt[c] == 0; i = sam[i].parent)
    sam[i].nxt[c] = cur;
  last = cur;
  if (i == 0) {
    sam[cur].parent = 1;
    sam[1].degree++;
    return;
  }
  j = sam[i].nxt[c];
  if (sam[i].len + 1 == sam[j].len) {
    sam[cur].parent = j;
    sam[j].degree++;
  } else {
    cloneQ = ++cntSam;
    sam[cloneQ] = sam[j];
    sam[cloneQ].len = sam[i].len + 1;
    for (; i != 0 && sam[i].nxt[c] == j; i = sam[i].parent)
      sam[i].nxt[c] = cloneQ;
    sam[j].parent = sam[cur].parent = cloneQ;
    sam[cloneQ].degree = 2;
  }
}
void get_string() {
  cntSam = last = 1;
  str[0] = 0;
  while (c < 'a' || c > 'z') c = getchar();
  while (c >= 'a' && c <= 'z') {
    str[++str[0]] = c - 'a';
    sam_extend(c - 'a');
    c = getchar();
  }
}
void radix_sort(int upper, int L) {
  int i;
  int t0, t1;
  memset(cnt, 0, sizeof(int) * (upper + 3));
  for (i = 1; i <= str[0]; i++) cnt[key[i]]++;
  for (i = 1; i <= upper; i++) cnt[i] += cnt[i - 1];
  for (i = str[0]; i; i--) sa[cnt[key[lastSA[i]]]--] = lastSA[i];
  for (t0 = 0, i = 1; i <= str[0]; i++) {
    t1 = sa[i] + L <= str[0] ? key[sa[i] + L] : -1;
    rk[sa[i]] = rk[sa[i - 1]] + (key[sa[i]] != key[sa[i - 1]] || t0 != t1);
    t0 = t1;
  }
}
void suffix_sort() {
  int i, j, k;
  for (i = 1; i <= str[0]; i++) {
    key[i] = str[i] + 1;
    lastSA[i] = i;
  }
  radix_sort(26, 0);
  for (i = 1; i < str[0]; i <<= 1) {
    for (j = 1; j <= i; j++) lastSA[j] = str[0] - j + 1;
    for (k = 1; k <= str[0]; k++) {
      if (sa[k] > i) lastSA[j++] = sa[k] - i;
      key[k] = rk[k];
    }
    radix_sort(str[0], i);
  }
  for (i = 1, k = 0; i <= str[0]; i++, k -= (k > 0)) {
    if (rk[i] == 1) continue;
    j = sa[rk[i] - 1];
    for (; i + k <= str[0] && j + k <= str[0] && str[i + k] == str[j + k]; k++)
      ;
    sparse[rk[i]][0] = k;
  }
  for (i = 1; (1 << i) <= str[0]; i++)
    for (j = 1; j + (1 << i) - 1 <= str[0]; j++)
      sparse[j][i] = min(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
}
inline int log2(int x) { return (int)(log(x) / log(2)); }
int tmpLog;
inline int lcp(int x, int y) {
  if (x > y) x ^= y ^= x ^= y;
  tmpLog = log2(y - x);
  return min(sparse[x + 1][tmpLog], sparse[y - (1 << tmpLog) + 1][tmpLog]);
}
void add_st(int &x, int l, int r, int p) {
  x = ++cntST;
  st[x].leftRk = st[x].rightRk = p;
  st[x].cnt = str[0] + 1 - sa[p];
  if (l == r) return;
  if (p <= ((l + r) >> 1))
    add_st(st[x].lp, l, ((l + r) >> 1), p);
  else
    add_st(st[x].rp, ((l + r) >> 1) + 1, r, p);
}
void merge_st(int &x, int y, int l, int r) {
  if (x == 0 || y == 0)
    x += y;
  else {
    merge_st(st[x].lp, st[y].lp, l, ((l + r) >> 1));
    merge_st(st[x].rp, st[y].rp, ((l + r) >> 1) + 1, r);
    st[x].leftRk = min(st[st[x].lp].leftRk == 0 ? 100005 : st[st[x].lp].leftRk,
                       st[st[x].rp].leftRk == 0 ? 100005 : st[st[x].rp].leftRk);
    st[x].rightRk = max(st[st[x].lp].rightRk, st[st[x].rp].rightRk);
    st[x].cnt = st[st[x].lp].cnt + st[st[x].rp].cnt;
    if (st[x].lp && st[x].rp)
      st[x].cnt -= lcp(st[st[x].lp].rightRk, st[st[x].rp].leftRk);
  }
}
void bfs() {
  int i, len = str[0];
  int p;
  closed = open = 0;
  for (i = p = 1; i <= len; i++) {
    p = sam[p].nxt[str[i]];
    if (i + 2 <= str[0]) add_st(stPointer[p], 1, len, rk[i + 2]);
    if (sam[p].degree == 0) {
      qhy[++open] = p;
      ans[3]--;
    }
  }
  do {
    closed++;
    if (qhy[closed] == 1) break;
    ans[1] += sam[qhy[closed]].len - sam[sam[qhy[closed]].parent].len;
    if (qhy[closed] != cntSam)
      ans[2] += sam[qhy[closed]].len - sam[sam[qhy[closed]].parent].len;
    ans[3] += sam[qhy[closed]].len - sam[sam[qhy[closed]].parent].len;
    ans[4] += st[stPointer[qhy[closed]]].cnt *
              (sam[qhy[closed]].len - sam[sam[qhy[closed]].parent].len);
    merge_st(stPointer[sam[qhy[closed]].parent], stPointer[qhy[closed]], 1,
             str[0]);
    sam[sam[qhy[closed]].parent].degree--;
    if (sam[sam[qhy[closed]].parent].degree == 0)
      qhy[++open] = sam[qhy[closed]].parent;
  } while (closed < open);
}
void standing_by() {
  get_string();
  suffix_sort();
}
void complete() {
  bfs();
  ans[0] = ans[1] + ans[2] + ans[3] + ans[4] + 2;
  printf("%lld\n", ans[0]);
}
int main() {
  standing_by();
  complete();
  return 0;
}
