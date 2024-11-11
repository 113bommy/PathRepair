#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
const int maxn = 200020;
const int maxm = 1000020;
const int MOd = 1e9 + 7;
const int P = 37;
int a;
int n, segment[1 << 18];
vector<pair<int, int> > w[maxn];
pair<int, int> ar[maxn];
int find(int l, int r) {
  int t = -1e9;
  for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
    if (l & 1) t = max(t, (segment[l]));
    if (~r & 1) t = max(t, (segment[r]));
  }
  return t;
}
void up(int k, int x) {
  k += n;
  for (; k; k >>= 1) segment[k] = min(segment[k], (x));
}
int main() {
  scanf("%d", &a);
  for (int i = 1; i <= a; i++) {
    scanf("%d %d", &ar[i].first, &ar[i].second);
    w[ar[i].second - ar[i].first + 100000].push_back(pair<int, int>(ar[i]));
  }
  int maxx = 200000;
  for (int i = 0; i <= maxx; i++)
    if (w[i].size()) {
      sort(w[i].begin(), w[i].end());
      reverse(w[i].begin(), w[i].end());
    }
  vector<pair<int, int> > ans;
  n = 1;
  while (n < 100000) n <<= 1;
  for (int i = 0; i < n + n; i++) segment[i] = -1e9;
  for (int i = 1, k; i <= a; i++) {
    scanf("%d", &k);
    k += 1e5;
    if (!w[k].size()) {
      printf("NO\n");
      return 0;
    }
    pair<int, int> t = w[k][w[k].size() - 1];
    if (find(t.first, n - 1) >= t.second) {
      printf("NO\n");
      return 0;
    }
    up(t.first, t.second);
    ans.push_back(w[k][w[k].size() - 1]);
    w[k].pop_back();
  }
  printf("YES\n");
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
