#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 2 * 200000;
const int MAXM = MAXN - 1;
int n;
int deg[MAXN];
int ghead[MAXN], gprv[2 * MAXM], gnxt[2 * MAXM], gto[2 * MAXM];
int ihead[MAXN], iprv[2 * MAXM], inxt[2 * MAXM];
int qhead, qprv[MAXN], qnxt[MAXN], qcopy[MAXN], nqcopy;
int mark[MAXN], curmark;
int rhead[MAXM], rcnt[MAXM], rnxt[MAXM];
void remdedge(int idx, int* head, int* prv, int* nxt) {
  if (head[gto[idx ^ 1]] == idx) head[gto[idx ^ 1]] = nxt[idx];
  if (prv[idx] != -1) nxt[prv[idx]] = nxt[idx];
  if (nxt[idx] != -1) prv[nxt[idx]] = prv[idx];
  prv[idx] = nxt[idx] = -1;
}
void remnode(int idx) {
  if (qhead == idx) qhead = qnxt[idx];
  if (qprv[idx] != -1) qnxt[qprv[idx]] = qnxt[idx];
  if (qnxt[idx] != -1) qprv[qnxt[idx]] = qprv[idx];
  qprv[idx] = qnxt[idx] = -1;
}
void repair(int idx) {
  rnxt[idx] = rhead[curmark];
  rhead[curmark] = idx;
  ++rcnt[curmark];
  int a = gto[2 * idx + 1], b = gto[2 * idx + 0];
  mark[a] = mark[b] = curmark;
  remdedge(2 * idx + 0, ghead, gprv, gnxt);
  remdedge(2 * idx + 1, ghead, gprv, gnxt);
  remdedge(2 * idx + 0, ihead, iprv, inxt);
  remdedge(2 * idx + 1, ihead, iprv, inxt);
  if (--deg[a] == 1) remdedge(ghead[a] ^ 1, ihead, iprv, inxt), remnode(a);
  if (--deg[b] == 1) remdedge(ghead[b] ^ 1, ihead, iprv, inxt), remnode(b);
}
void process(int at) {
  int idx = -1;
  for (int x = ghead[at]; x != -1; x = gnxt[x])
    if (mark[gto[x]] != curmark) {
      idx = x >> 1;
      break;
    }
  if (idx == -1) {
    printf("error: curmark=%d, cnt=%d, at=%d\n", curmark, rcnt[curmark], at);
    exit(0);
  }
  repair(idx);
  for (int x = ihead[gto[2 * idx + 0]]; x != -1;) {
    int y = x;
    x = inxt[x];
    if (mark[gto[y]] != curmark) process(gto[y]);
  }
  for (int x = ihead[gto[2 * idx + 1]]; x != -1;) {
    int y = x;
    x = inxt[x];
    if (mark[gto[x]] != curmark) process(gto[y]);
  }
}
void run() {
  n = MAXN;
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) ghead[i] = -1, deg[i] = 0;
  for (int i = (0); i < (n - 1); ++i) {
    int a = 0, b = i + 1;
    scanf("%d%d", &a, &b);
    --a, --b;
    gnxt[2 * i + 0] = ghead[a];
    ghead[a] = 2 * i + 0;
    gto[2 * i + 0] = b;
    gprv[2 * i + 0] = -1;
    if (gnxt[2 * i + 0] != -1) gprv[gnxt[2 * i + 0]] = 2 * i + 0;
    ++deg[a];
    gnxt[2 * i + 1] = ghead[b];
    ghead[b] = 2 * i + 1;
    gto[2 * i + 1] = a;
    gprv[2 * i + 1] = -1;
    if (gnxt[2 * i + 1] != -1) gprv[gnxt[2 * i + 1]] = 2 * i + 1;
    ++deg[b];
  }
  for (int at = (0); at < (n); ++at) {
    ihead[at] = -1;
    for (int x = ghead[at]; x != -1; x = gnxt[x])
      if (deg[gto[x]] >= 2) {
        inxt[x] = ihead[at];
        ihead[at] = x;
        iprv[x] = -1;
        if (inxt[x] != -1) iprv[inxt[x]] = x;
      } else
        iprv[x] = inxt[x] = -1;
  }
  qhead = -1;
  for (int at = (0); at < (n); ++at)
    if (deg[at] >= 2) {
      qnxt[at] = qhead;
      qhead = at;
      qprv[at] = -1;
      if (qnxt[at] != -1) qprv[qnxt[at]] = at;
    } else
      qprv[at] = qnxt[at] = -1;
  for (int at = (0); at < (n - 1); ++at) rnxt[at] = -1;
  memset(mark, -1, sizeof(mark));
  curmark = -1;
  while (true) {
    ++curmark;
    rhead[curmark] = -1, rcnt[curmark] = 0;
    nqcopy = 0;
    for (int at = qhead; at != -1; at = qnxt[at]) qcopy[nqcopy++] = at;
    if (nqcopy == 0)
      for (int at = (0); at < (n); ++at)
        if (deg[at] >= 1) qcopy[nqcopy++] = at;
    if (nqcopy == 0) break;
    for (int i = (0); i < (nqcopy); ++i) {
      int at = qcopy[i];
      if (mark[at] != curmark) process(at);
    }
  }
  printf("%d\n", curmark);
  for (int i = (0); i < (curmark); ++i) {
    printf("%d", rcnt[i]);
    fflush(stdout);
    for (int x = rhead[i]; x != -1; x = rnxt[x])
      printf(" %d", x + 1), fflush(stdout);
    puts("");
    fflush(stdout);
  }
}
int main() {
  run();
  return 0;
}
