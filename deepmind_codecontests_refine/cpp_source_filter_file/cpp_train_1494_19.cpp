#include <bits/stdc++.h>
using namespace std;
struct node {
  int c, id;
  bool operator<(const node& a) const {
    if (c == a.c) return id < a.id;
    return c < a.c;
  }
} cube[200005];
int n, m, k;
int b[200005], num[200005], gap[200005];
bool judge(int mid) {
  int i, j, del;
  if (mid == 1) return 1;
  i = 0;
  while (i < n) {
    if (num[cube[i].c] >= mid) {
      del = 0;
      for (j = 1; j < mid; j++) del += gap[i + j];
      if (del <= k) return 1;
      for (j = mid; j < num[cube[i].c]; j++) {
        del += gap[i + j] - gap[i + j - mid + 1];
        if (del <= mid) return 1;
      }
    }
    i += num[cube[i].c];
  }
  return 0;
}
void binary() {
  int low, high, mid;
  low = 0;
  high = n;
  memset(num, 0, sizeof(num));
  for (int i = 0; i < n; i++) {
    cube[i].c = b[i];
    cube[i].id = i;
    num[b[i]]++;
  }
  sort(cube, cube + n);
  for (int i = 1; i < n; i++) gap[i] = cube[i].id - cube[i - 1].id - 1;
  while (low < high - 1) {
    mid = (low + high) >> 1;
    if (judge(mid))
      low = mid;
    else
      high = mid - 1;
  }
  if (judge(high)) low = high;
  cout << low << endl;
}
int main() {
  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; i++) cin >> b[i];
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    binary();
  }
  return 0;
}
