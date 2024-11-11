#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC target(sse, sse2, sse3, ssse3, sse4, popcnt, tune = native)
#pragma GCC optimize(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
    "-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", \
    3)
using namespace std;
const int MAXN = 1e6 + 47;
int n;
vector<int> graf[MAXN];
void read() {
  cin >> n;
  int p1, p2;
  for (int i = 0; i < n - 1; i++) {
    cin >> p1 >> p2;
    --p1, --p2;
    graf[p1].push_back(p2);
    graf[p2].push_back(p1);
  }
}
int H[MAXN], sz[MAXN], ans[MAXN];
void prep(int p1, int pr) {
  sz[p1]++;
  for (int p2 : graf[p1]) {
    if (p2 == pr) continue;
    prep(p2, p1);
    sz[p1] += sz[p2];
  }
}
void add(int p1, int pr, int h, int man) {
  H[h]++;
  if (H[h] >= H[ans[man]]) {
    if (H[h] == H[ans[man]])
      ans[man] = min(ans[man], h);
    else
      ans[man] = h;
  }
  for (int p2 : graf[p1]) {
    if (p2 == pr) continue;
    add(p2, p1, h + 1, man);
  }
}
void erase(int p1, int pr, int h) {
  H[h]--;
  for (int p2 : graf[p1]) {
    if (p2 != pr) erase(p2, p1, h + 1);
  }
}
void dfs(int p1, int pr, int h, bool keep) {
  int mx = -1, big = -1;
  for (int p2 : graf[p1]) {
    if (p2 == pr) continue;
    if (sz[p2] > mx) big = p2, mx = sz[p2];
  }
  for (int p2 : graf[p1]) {
    if (p2 == pr || p2 == big) continue;
    dfs(p2, p1, h + 1, false);
  }
  if (big != -1) dfs(big, p1, h + 1, true), ans[p1] = ans[big] + h - 1;
  H[h]++;
  if (H[h] >= H[ans[p1]]) {
    if (H[h] == H[ans[p1]])
      ans[p1] = min(ans[p1], h);
    else
      ans[p1] = h;
  }
  for (int p2 : graf[p1]) {
    if (p2 == pr || p2 == big) continue;
    add(p2, p1, h + 1, p1);
  }
  ans[p1] -= h;
  if (!keep) {
    H[h]--;
    for (int p2 : graf[p1]) {
      if (p2 == pr) continue;
      erase(p2, p1, h + 1);
    }
  }
}
void solve() {
  prep(0, -1);
  dfs(0, -1, 0, false);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read();
  solve();
}
