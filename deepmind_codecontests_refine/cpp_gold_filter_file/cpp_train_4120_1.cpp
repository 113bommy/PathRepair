#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 2000;
const string YES = "YES";
const string NO = "NO";
int n, a, b;
int s[MAXN];
int pos[MAXN];
int need[MAXN];
int stck[MAXN], nstck;
pair<int, int> mid[MAXN];
int nmid, ndst;
vector<pair<int, int> > ops;
bool take(int &at, int cnt) {
  if (cnt > a) return false;
  for (int i = at + cnt - 1; i >= at; --i) {
    if (nmid != 0 && s[i] == mid[nmid - 1].first - 1)
      --mid[nmid - 1].first;
    else if (nmid != 0 && s[i] <= mid[nmid - 1].second)
      return false;
    else
      mid[nmid++] = make_pair(s[i], s[i]);
  }
  ops.push_back(make_pair(1, cnt));
  at += cnt;
  while (nmid > 0 && mid[nmid - 1].second == n - ndst - 1) {
    int len = mid[nmid - 1].second - mid[nmid - 1].first + 1;
    if (len > b) return false;
    ops.push_back(make_pair(2, len));
    ndst += len;
    --nmid;
  }
  return true;
}
bool bcan(int at, int cnt) {
  if (cnt == 0) return true;
  int prv = s[at], mn = s[at], len = 1;
  for (int i = (1); i < (cnt); ++i) {
    int now = s[at + i];
    if (len < b && now == prv + 1) {
      prv = now, ++len;
      continue;
    }
    if (now < mn) {
      prv = mn = now, len = 1;
      continue;
    }
    return false;
  }
  return true;
}
bool solve() {
  for (int i = (0); i < (n); ++i) pos[s[i]] = i;
  nstck = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (nstck == 0 || s[i] > s[stck[nstck - 1]]) {
      need[i] = i;
      stck[nstck++] = i;
    } else {
      int l = -1, h = nstck - 1;
      while (l + 1 < h) {
        int m = l + (h - l) / 2;
        if (s[i] <= s[stck[m]])
          h = m;
        else
          l = m;
      }
      need[i] = stck[h];
    }
  }
  nmid = ndst = 0;
  ops.clear();
  int at = 0;
  while (at < n) {
    int top = nmid == 0 ? -1 : mid[nmid - 1].first;
    bool nosmall = true;
    for (int i = (at + 1); i < (need[at]); ++i)
      if (s[i] < s[at]) nosmall = false;
    if (top != -1 && top != 0 && pos[top - 1] >= at &&
        need[at] >= pos[top - 1]) {
      if (!take(at, pos[top - 1] - at + 1)) return false;
    } else if (s[at] == 0 || pos[s[at] - 1] < at ||
               need[at] < pos[s[at] - 1] && nosmall) {
      if (need[at] == at) {
        if (!take(at, 1)) return false;
      } else {
        int extra = 0;
        while (at + 1 + extra < n && s[at + 1 + extra] < s[at]) ++extra;
        if (!take(at, 1 + extra)) return false;
      }
    } else {
      int to = pos[s[at] - 1];
      int atlen = 1;
      while (at + atlen < n && s[at + atlen] == s[at] + atlen) ++atlen;
      int tolen = 1;
      while (to - tolen >= 0 && s[to - tolen] == s[to] - tolen) ++tolen;
      if (at + atlen + tolen - 1 != to) {
        int extra = 0;
        while (at + atlen + extra < n && s[at + atlen + extra] < s[at] &&
               s[at + atlen + extra] != s[at] - tolen)
          ++extra;
        if (!take(at, atlen + extra)) return false;
      } else {
        int extra = 0;
        while (at + atlen + tolen + extra < n &&
               s[at + atlen + tolen + extra] < s[at])
          ++extra;
        bool other = false;
        for (int i = (at + atlen + tolen + extra); i < (need[at]); ++i)
          if (s[i] < s[at]) other = true;
        if (!other && atlen + tolen + extra <= a && atlen <= b && tolen <= b &&
            bcan(at + atlen + tolen, extra)) {
          if (!take(at, atlen + tolen + extra)) return false;
        } else if (atlen <= a && tolen <= a && atlen + tolen <= b) {
          if (!take(at, atlen)) return false;
          if (!take(at, tolen)) return false;
        } else {
          int x = 0;
          while (x <= atlen + tolen &&
                 !(x <= a && atlen + tolen - x <= a &&
                   (x <= atlen ? tolen + x : x - atlen) <= b &&
                   (x <= atlen ? atlen - x : atlen + tolen - x + atlen) <= b))
            ++x;
          if (x > atlen + tolen) return false;
          if (x != 0 && !take(at, x)) return false;
          if (!take(at, atlen + tolen - x)) return false;
        }
      }
    }
  }
  assert(nmid == 0 && ndst == n);
  return true;
}
void run() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = (0); i < (n); ++i) scanf("%d", &s[i]), --s[i];
  if (!solve()) {
    cout << NO << endl;
    return;
  }
  cout << YES << endl;
  printf("%d\n", ((int)(ops).size()));
  for (int i = (0); i < (((int)(ops).size())); ++i)
    printf("%d %d\n", ops[i].first, ops[i].second);
}
int main() {
  run();
  return 0;
}
