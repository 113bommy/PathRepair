#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int lg[N];
int ma[N][21];
int mi[N][21];
int sum[N];
vector<int> num[110];
int a[N];
void init() {
  int i;
  lg[1] = 0;
  lg[2] = 1;
  for (i = 3; i < N; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
}
int find(int opt, int l, int r) {
  if (opt == 1) {
    int p = lg[r - l + 1];
    return min(mi[l][p], mi[r - (1 << p) + 1][p]);
  } else {
    int p = lg[r - l + 1];
    return max(ma[l][p], ma[r - (1 << p) + 1][p]);
  }
}
int main() {
  init();
  int n;
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
    num[a[i] + 30].push_back(i);
  }
  int j;
  for (j = 0; j < 21; j++) {
    for (i = 0; i + (1 << j) - 1 <= n; i++) {
      if (j == 0) {
        ma[i][j] = sum[i];
        mi[i][j] = sum[i];
      } else {
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int res = -0x3f3f3f3f;
  for (i = 1; i <= n; i++) {
    int l = 1, r = n;
    for (j = a[i] + 1; j <= 30; j++) {
      int pos = lower_bound(num[j + 30].begin(), num[j + 30].end(), i) -
                num[j + 30].begin();
      if (pos < (int)num[j + 30].size()) r = min(r, num[j + 30][pos] - 1);
      if (pos >= 1) l = max(l, num[j + 30][pos - 1] + 1);
    }
    int pre = find(1, l - 1, i);
    int nxt = find(2, i, r);
    res = max(res, nxt - pre - a[i]);
  }
  cout << max(res, 0) << endl;
}
