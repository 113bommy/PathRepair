#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
int n, need, want;
int c[MAXN];
int like[MAXN];
vector<int> opt[4];
long long solve() {
  long long ret = LLONG_MAX;
  long long cur = 0;
  int ata = 0, atb = 0, likea = 0, likeb = 0, cnt = 0;
  priority_queue<int> avail, have;
  int mnboth =
      max(want - ((int)(opt[1]).size()), want - ((int)(opt[2]).size()));
  int mxboth = min(want, ((int)(opt[3]).size()));
  if (mnboth > mxboth) return -1;
  for (int i = (0); i < (mnboth); ++i)
    cur += opt[3][i], ++likea, ++likeb, ++cnt;
  for (int i = (mxboth); i < (((int)(opt[3]).size())); ++i)
    avail.push(-opt[3][i]);
  while (likea < want && ata < ((int)(opt[1]).size()))
    cur += opt[1][ata++], ++likea, ++cnt;
  for (int i = (ata); i < (((int)(opt[1]).size())); ++i) avail.push(-opt[1][i]);
  while (likeb < want && atb < ((int)(opt[2]).size()))
    cur += opt[2][atb++], ++likeb, ++cnt;
  for (int i = (atb); i < (((int)(opt[2]).size())); ++i) avail.push(-opt[2][i]);
  for (int i = (0); i < (((int)(opt[0]).size())); ++i) avail.push(-opt[0][i]);
  while (cnt < need && !avail.empty()) {
    cur -= avail.top(), have.push(-avail.top()), ++cnt;
    avail.pop();
  }
  for (int atboth = (mnboth); atboth <= (mxboth); ++atboth) {
    if (likea >= want && likeb >= want && cnt == need) ret = min(ret, cur);
    if (atboth < mxboth) {
      cur += opt[3][atboth], ++likea, ++likeb, ++cnt;
      if (likea > want && ata > 0)
        cur -= opt[1][--ata], --likea, --cnt, avail.push(-opt[1][ata]);
      if (likeb > want && atb > 0)
        cur -= opt[2][--atb], --likeb, --cnt, avail.push(-opt[2][atb]);
      while (cnt > need && !have.empty()) {
        cur -= have.top(), avail.push(-have.top()), --cnt;
        have.pop();
      }
      while (cnt < need && !avail.empty()) {
        cur -= avail.top(), have.push(-avail.top()), ++cnt;
        avail.pop();
      }
      while (!avail.empty() && !have.empty() && -avail.top() < have.top()) {
        int c = -avail.top(), d = have.top();
        avail.pop(), have.pop();
        cur += c - d;
        avail.push(-d), have.push(c);
      }
    }
  }
  return ret == LLONG_MAX ? -1 : ret;
}
void run() {
  scanf("%d%d%d", &n, &need, &want);
  for (int i = (0); i < (n); ++i) scanf("%d", &c[i]), like[i] = 0;
  {
    int na;
    scanf("%d", &na);
    for (int i = (0); i < (na); ++i) {
      int x;
      scanf("%d", &x);
      --x;
      like[x] |= 1;
    }
  }
  {
    int nb;
    scanf("%d", &nb);
    for (int i = (0); i < (nb); ++i) {
      int x;
      scanf("%d", &x);
      --x;
      like[x] |= 2;
    }
  }
  for (int i = (0); i < (4); ++i) opt[i].clear();
  for (int i = (0); i < (n); ++i) opt[like[i]].push_back(c[i]);
  for (int i = (0); i < (4); ++i) sort(opt[i].begin(), opt[i].end());
  printf("%lld\n", solve());
}
int main() {
  run();
  return 0;
}
