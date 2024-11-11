#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int MAXM = 30;
char a[MAXN], c[MAXN];
int len1, len2;
pair<int, int> go[MAXM][MAXN * MAXN];
int get_id(int i, int j) { return i * len2 + j; }
long long solve(int dis) {
  int cur = get_id(0, 0);
  long long cot = 0;
  for (int i = 0; i < MAXM; i++) {
    if (dis >> i & 1) {
      cot += go[i][cur].second;
      cur = go[i][cur].first;
    }
  }
  return cot;
}
int main() {
  int b, d;
  scanf("%d%d", &b, &d);
  scanf("%s%s", a, c);
  len1 = strlen(a);
  len2 = strlen(c);
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      int id = get_id(i, j);
      go[0][id] = make_pair(id, 0x3f3f3f3f);
      for (int k = 0; k < len1; k++) {
        if (a[(i + k) % len1] == c[j]) {
          go[0][id] = make_pair((get_id((i + k + 1) % len1, (j + 1) % len2)),
                                (i == 0) || ((i + k) / len1));
          break;
        }
      }
    }
  }
  for (int i = 1; i < MAXM; i++) {
    for (int j = 0; j < len1 * len2; j++) {
      int nxt = go[i - 1][j].first;
      go[i][j] = make_pair(go[i - 1][nxt].first,
                           go[i - 1][j].second + go[i - 1][nxt].second);
    }
  }
  int l = 0;
  int r = 0x3f3f3f3f;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (solve(mid) <= b) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d\n", l / (len2 * d));
  return 0;
}
