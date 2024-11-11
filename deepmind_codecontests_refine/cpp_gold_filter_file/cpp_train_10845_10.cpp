#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 105;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, r;
vector<pair<int, int> > va, vb;
int cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int cmp2(pair<int, int> a, pair<int, int> b) {
  return a.second + b.first < a.first + b.second;
}
int main(void) {
  scanf("%d%d", &n, &r);
  int x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    if (y >= 0)
      va.push_back(pair<int, int>(x, y));
    else
      vb.push_back(pair<int, int>(x, -y));
  }
  sort(va.begin(), va.end(), cmp);
  sort(vb.begin(), vb.end(), cmp2);
  int cur = r, flag = 0;
  for (int i = 0; i < va.size(); i++) {
    if (va[i].first > cur) {
      flag = 1;
      break;
    }
    cur += va[i].second;
  }
  if (flag) {
    puts("NO");
    return 0;
  }
  flag = 0;
  for (int i = 0; i < vb.size(); i++) {
    if (vb[i].first > cur) {
      flag = 1;
      break;
    }
    cur -= vb[i].second;
  }
  if (flag || cur < 0) {
    puts("NO");
  } else
    puts("YES");
  return 0;
}
