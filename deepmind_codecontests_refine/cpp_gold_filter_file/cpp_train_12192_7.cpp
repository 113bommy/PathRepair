#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, flow, next;
} e[3000050];
int n, now, maxflow, ansrs, anscs, S, T, first[2222], last[2222], q[2222],
    level[2222], arrx[2222], arry[2222];
int rows, cols;
bool temp[2222][2222], have[2222][2222], isS[2222], user[2222], usec[2222];
pair<int, int> p[2222], d[2222];
pair<int, pair<int, int> > row[2222], col[2222];
pair<pair<int, int>, pair<int, int> > ansr[2222 * 2222], ansc[2222 * 2222];
void Add(int u, int v, int w) {
  e[++now].to = v;
  e[now].flow = w;
  e[now].next = first[u];
  first[u] = now;
}
bool Level() {
  int low, high, pt, next;
  memset(level, -1, sizeof(level));
  q[low = high = 0] = S;
  level[S] = 0;
  for (; low <= high; low++)
    for (pt = first[q[low]]; pt != -1; pt = e[pt].next) {
      next = e[pt].to;
      if (level[next] != -1 || e[pt].flow <= 0) continue;
      level[next] = level[q[low]] + 1;
      q[++high] = next;
      if (next == T) return true;
    }
  return false;
}
int Find(int first, int delta) {
  int pt, next, temp, res = 0;
  if (first == T || delta <= 0) return delta;
  for (pt = last[first]; pt != -1; last[first] = pt = e[pt].next) {
    next = e[pt].to;
    if (level[next] != level[first] + 1) continue;
    temp = Find(next, min(delta, e[pt].flow));
    delta -= temp;
    res += temp;
    e[pt].flow -= temp;
    e[pt ^ 1].flow += temp;
    if (delta <= 0) return res;
  }
  return res;
}
void BFS() {
  int low, high, pt, next;
  memset(isS, false, sizeof(isS));
  q[low = high = 0] = S;
  isS[S] = true;
  for (; low <= high; low++)
    for (pt = first[q[low]]; pt != -1; pt = e[pt].next) {
      next = e[pt].to;
      if (isS[next] || e[pt].flow <= 0) continue;
      isS[next] = true;
      q[++high] = next;
    }
}
void Output(pair<pair<int, int>, pair<int, int> > pa) {
  printf("%d %d %d %d\n", arrx[pa.first.first], arry[pa.first.second],
         arrx[pa.second.first], arry[pa.second.second]);
}
int main() {
  int i, j, rec, arrxs, arrys, pt, next;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d", &p[i].first, &p[i].second), arrx[i] = p[i].first,
                                              arry[i] = p[i].second;
  sort(arrx + 1, arrx + n + 1);
  arrxs = unique(arrx + 1, arrx + n + 1) - arrx - 1;
  sort(arry + 1, arry + n + 1);
  arrys = unique(arry + 1, arry + n + 1) - arry - 1;
  for (i = 1; i <= n; i++) {
    d[i].first = lower_bound(arrx + 1, arrx + arrxs + 1, p[i].first) - arrx;
    d[i].second = lower_bound(arry + 1, arry + arrys + 1, p[i].second) - arry;
    have[d[i].first][d[i].second] = true;
  }
  for (i = 1; i <= arrxs; i++) {
    rec = -1;
    for (j = 1; j <= arrys; j++)
      if (have[i][j]) {
        if (rec != -1 && rec + 1 < j)
          row[++rows] = make_pair(i, make_pair(rec + 1, j - 1));
        rec = j;
      }
  }
  for (j = 1; j <= arrys; j++) {
    rec = -1;
    for (i = 1; i <= arrxs; i++)
      if (have[i][j]) {
        if (rec != -1 && rec + 1 < i)
          col[++cols] = make_pair(j, make_pair(rec + 1, i - 1));
        rec = i;
      }
  }
  S = 0;
  T = rows + cols + 1;
  memset(first, -1, sizeof(first));
  now = -1;
  for (i = 1; i <= rows; i++) Add(S, i, 1), Add(i, S, 0);
  for (i = 1; i <= cols; i++) Add(rows + i, T, 1), Add(T, rows + i, 0);
  for (i = 1; i <= rows; i++)
    for (j = 1; j <= cols; j++)
      if (col[j].second.first <= row[i].first &&
          row[i].first <= col[j].second.second &&
          row[i].second.first <= col[j].first &&
          col[j].first <= row[i].second.second)
        Add(i, rows + j, 999999999), Add(rows + j, i, 0);
  while (Level()) {
    memcpy(last, first, sizeof(last));
    maxflow += Find(S, 999999999);
  }
  BFS();
  memset(user, true, sizeof(user));
  memset(usec, true, sizeof(usec));
  for (i = S; i <= T; i++)
    if (isS[i])
      for (pt = first[i]; pt != -1; pt = e[pt].next) {
        next = e[pt].to;
        if (isS[next]) continue;
        if (i == S)
          user[next] = false;
        else
          usec[i - rows] = false;
      }
  memcpy(temp, have, sizeof(temp));
  for (i = 1; i <= cols; i++)
    if (usec[i])
      for (j = col[i].second.first; j <= col[i].second.second; j++)
        temp[j][col[i].first] = true;
  for (j = 1; j <= arrys; j++) {
    rec = 0;
    for (i = 1; i <= arrxs; i++)
      if (!temp[i][j]) {
        if (rec + 1 < i)
          ansc[++anscs] = make_pair(make_pair(rec + 1, j), make_pair(i - 1, j));
        rec = i;
      }
    if (rec < arrxs)
      ansc[++anscs] = make_pair(make_pair(rec + 1, j), make_pair(arrxs, j));
  }
  memcpy(temp, have, sizeof(temp));
  for (i = 1; i <= rows; i++)
    if (user[i])
      for (j = row[i].second.first; j <= row[i].second.second; j++)
        temp[row[i].first][j] = true;
  for (i = 1; i <= arrxs; i++) {
    rec = 0;
    for (j = 1; j <= arrys; j++)
      if (!temp[i][j]) {
        if (rec + 1 < j)
          ansr[++ansrs] = make_pair(make_pair(i, rec + 1), make_pair(i, j - 1));
        rec = j;
      }
    if (rec < arrys)
      ansr[++ansrs] = make_pair(make_pair(i, rec + 1), make_pair(i, arrys));
  }
  printf("%d\n", anscs);
  for (i = 1; i <= anscs; i++) Output(ansc[i]);
  printf("%d\n", ansrs);
  for (i = 1; i <= ansrs; i++) Output(ansr[i]);
  return 0;
}
