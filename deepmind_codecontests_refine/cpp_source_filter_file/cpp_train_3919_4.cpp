#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 69;
long long n, res, first[N], col[N];
long long dis(int l, int r) {
  if (l == -1 || r == -1) return 0;
  return abs(first[r] - first[l]);
}
int find_left(int l, int r, int c) {
  for (int i = l; i <= r; i++)
    if (col[i] == c) return i;
  return -1;
}
int find_right(int l, int r, int c) {
  for (int i = r; i >= l; i--)
    if (col[i] == c) return i;
  return -1;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> first[i] >> c;
    if (c == 'G') col[i] = 0;
    if (c == 'R') col[i] = 1;
    if (c == 'B') col[i] = 2;
  }
  int l = find_left(1, n, 0), r = find_right(1, n, 0);
  if (l == -1) {
    for (int i = 1; i <= 2; i++)
      res += dis(find_left(1, n, i), find_right(1, n, i));
    cout << res;
    return 0;
  }
  for (int i = 1; i <= 2; i++)
    res += dis(find_left(1, l, i), l) + dis(find_right(r, n, i), r);
  while (l < r) {
    long long m = find_left(l + 1, r, 0), len = first[m] - first[l],
              delta[3] = {0, 0, 0};
    for (int i = 1; i <= 2; i++) {
      long long j = l, pre = l;
      while (1) {
        int j = find_left(j + 1, m, i);
        if (j == -1) break;
        delta[i] = max(delta[i], dis(pre, j));
        pre = j;
      }
      delta[i] = max(delta[i], dis(pre, m));
    }
    res += min(2 * len, 3 * len - delta[1] - delta[2]);
    l = m;
  }
  cout << res;
}
