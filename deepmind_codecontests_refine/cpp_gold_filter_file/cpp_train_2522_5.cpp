#include <bits/stdc++.h>
void rd(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
void lrd(long long &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
const int INF = 1e9;
const long long LINF = 1e18;
const int N = 4e4 + 10;
using namespace std;
int n, m, k;
int a[N], b[N];
vector<int> S1, S2;
int s1[N], s2[N];
long long ans;
void work(int x, int y) {
  if (lower_bound(S1.begin(), S1.end(), x) == S1.end()) return;
  if (lower_bound(S2.begin(), S2.end(), y) == S2.end()) return;
  int id1 = lower_bound(S1.begin(), S1.end(), x) - S1.begin(),
      id2 = lower_bound(S2.begin(), S2.end(), y) - S2.begin();
  ans += (s1[id1] - (S1.size() - id1) * (x - 1)) *
         (s2[id2] - (S2.size() - id2) * (y - 1));
}
int main() {
  rd(n);
  rd(m);
  rd(k);
  for (int i = 1; i <= n; i++) rd(a[i]);
  for (int i = 1; i <= m; i++) rd(b[i]);
  int now = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (a[i])
      now++;
    else {
      if (now) S1.push_back(now);
      now = 0;
    }
  }
  for (int i = 1; i <= m + 1; i++) {
    if (b[i])
      now++;
    else {
      if (now) S2.push_back(now);
      now = 0;
    }
  }
  sort(S1.begin(), S1.end());
  sort(S2.begin(), S2.end());
  for (int i = S1.size() - 1; i >= 0; i--) s1[i] = s1[i + 1] + S1[i];
  for (int i = S2.size() - 1; i >= 0; i--) s2[i] = s2[i + 1] + S2[i];
  int t = sqrt(k);
  for (int i = 1; i <= t; i++) {
    if (k % i) continue;
    work(i, k / i);
    if (i != k / i) work(k / i, i);
  }
  printf("%lld\n", ans);
  return 0;
}
