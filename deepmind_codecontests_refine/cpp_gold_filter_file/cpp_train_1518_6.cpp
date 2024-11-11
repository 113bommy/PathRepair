#include <bits/stdc++.h>
using namespace std;
void timestamp(char const* const s, bool absolute = false);
int n, t, k;
int a[200000];
int parent[200000];
void read() {
  cin >> n >> t >> k;
  for (int i = 0; i < t; ++i) {
    cin >> a[i];
  }
}
void solve() {
  int leaves = 1;
  int cpos = 1;
  int cparent = 0;
  for (int tt = 0; tt < t; tt++) {
    int level_parent = cpos;
    for (int v = 0; v < a[tt]; v++) {
      parent[cpos++] = cparent;
    }
    cparent = level_parent;
    leaves += a[tt] - 1;
  }
  if (leaves < k) {
    cout << -1 << endl;
    return;
  }
  if (leaves > k) {
    int parent_start = 1;
    int parent_end = 1 + a[0];
    for (int tt = 1; tt < t; tt++) {
      int current_start = parent_end;
      int current_end = current_start + a[tt];
      int upparent = parent_start + 1;
      bool ok = false;
      for (int i = current_start + 1; upparent < parent_end && i < current_end;
           i++) {
        parent[i] = upparent++;
        leaves--;
        if (leaves == k) {
          ok = true;
          break;
        }
      }
      if (ok) break;
      parent_start = current_start;
      parent_end = current_end;
    }
  }
  if (leaves > k) {
    printf("-1\n");
  } else {
    printf("%d\n", n);
    for (int i = 1; i < n; i++) {
      printf("%d %d\n", i + 1, parent[i] + 1);
    }
  }
}
void timestamp(char const* const s, bool absolute) {
  static double last = 0;
  double now = ((double)clock() / CLOCKS_PER_SEC) * 1000;
  if (absolute) {
    ;
  } else {
    ;
    last = now;
  }
}
int main() {
  read();
  solve();
  return 0;
}
