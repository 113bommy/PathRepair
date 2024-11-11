#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int BLOCK = 700;
const int INF = 1000000001;
pair<int, int> arr[N];
int add[BLOCK + 100];
int n, m;
void update(int l, int r, int x) {
  l--;
  r--;
  int block_l = l / BLOCK;
  int block_r = r / BLOCK;
  if (block_l == block_r) {
    int ll = block_l * BLOCK;
    int rr = min(n - 1, ll + BLOCK - 1);
    for (int i = ll; i <= rr; i++)
      if (l <= arr[i].second && arr[i].second <= r)
        arr[i].first = min(INF, arr[i].first + x);
    sort(arr + ll, arr + rr + 1);
  } else {
    int ll = block_l * BLOCK;
    int rr = ll + BLOCK - 1;
    for (int i = ll; i <= rr; i++)
      if (l <= arr[i].second) arr[i].first = min(INF, arr[i].first + x);
    sort(arr + ll, arr + rr + 1);
    for (int i = block_l + 1; i < block_r; i++) add[i] = min(INF, add[i] + x);
    ll = block_r * BLOCK;
    rr = min(n - 1, ll + BLOCK - 1);
    for (int i = ll; i <= rr; i++)
      if (arr[i].second <= rr) arr[i].first = min(INF, arr[i].first + x);
    sort(arr + ll, arr + rr + 1);
  }
}
void query(int y) {
  int mins = INF, maks = -INF;
  for (int i = 0; i < n; i += BLOCK) {
    int l = i;
    int r = min(n - 1, l + BLOCK - 1);
    int lol = y - add[i / BLOCK];
    int pos = lower_bound(arr + l, arr + r + 1, make_pair(lol, 0)) - arr;
    if (pos > r || arr[pos].first != lol) continue;
    int pos2 = upper_bound(arr + l, arr + r + 1, make_pair(lol, INF)) - arr;
    pos2--;
    mins = min(mins, arr[pos].second);
    maks = max(maks, arr[pos2].second);
  }
  if (mins == INF)
    puts("-1");
  else
    printf("%d\n", maks - mins);
}
void init() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
  }
  for (int i = 0; i < n; i += BLOCK) {
    int l = i;
    int r = min(n - 1, l + BLOCK - 1);
    sort(arr + l, arr + r + 1);
  }
}
void solve() {
  for (int i = 1; i <= m; i++) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      update(l, r, x);
    } else {
      int y;
      scanf("%d", &y);
      query(y);
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}
