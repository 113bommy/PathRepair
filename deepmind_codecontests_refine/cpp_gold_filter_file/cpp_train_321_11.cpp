#include <bits/stdc++.h>
using namespace std;
int getInt();
int getNegInt();
int T, N;
int get_nearest(int p, int a, vector<vector<int> >& path,
                unordered_set<int>& me) {
  if (me.find(a) != me.end()) return a;
  for (auto b : path[a]) {
    if (b == p) continue;
    int tar = get_nearest(a, b, path, me);
    if (tar != -1) return tar;
  }
  return -1;
}
int main(int argc, char** argv) {
  int a, b, k1, k2;
  T = getInt();
  while (T--) {
    unordered_set<int> me, he;
    N = getInt();
    vector<vector<int> > path(N + 1, vector<int>());
    for (int i = 1; i < N; i++) {
      scanf("%d%d", &a, &b);
      path[a].push_back(b);
      path[b].push_back(a);
    }
    k1 = getInt();
    int start;
    for (int i = 1; i <= k1; i++) {
      a = getInt();
      me.insert(a);
    }
    k2 = getInt();
    for (int i = 1; i <= k2; i++) {
      b = getInt();
      start = b;
      he.insert(b);
    }
    int ans = -1;
    for (int i = 1; i <= 1; i++) {
      cout << "B " << start << endl;
      fflush(stdout);
      int index = getInt();
      if (me.find(index) != me.end()) {
        ans = index;
        break;
      }
      int nearest = get_nearest(index, index, path, me);
      cout << "A " << nearest << endl;
      fflush(stdout);
      index = getInt();
      if (he.find(index) != he.end()) {
        ans = nearest;
        break;
      }
    }
    cout << "C " << ans << endl;
    fflush(stdout);
  }
  return 0;
}
int getInt() {
  int ret = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') ret *= 10, ret += c - '0', c = getchar();
  return ret;
}
int getNegInt() {
  int ret = 0, sign = 1;
  char c = getchar();
  while ((c < '0' && c != '-') || c > '9') c = getchar();
  if (c == '-') sign = -1, c = getchar();
  while (c >= '0' && c <= '9') ret *= 10, ret += c - '0', c = getchar();
  return ret * sign;
}
