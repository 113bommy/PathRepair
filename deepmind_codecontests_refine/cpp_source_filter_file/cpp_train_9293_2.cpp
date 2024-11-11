#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
int k, m, n, num = 2e5;
vector<int> P[maxn];
set<pair<int, int> > S;
set<pair<int, int> >::iterator it;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= num; i++) {
    for (int j = i; j <= num; j += i) {
      P[j].push_back(i);
    }
  }
  long long l, r;
  scanf("%lld%lld", &l, &r);
  long long ll = m + 1, rr = m;
  for (int x = 1; x <= n; x++) {
    long long L = (l - 1) / x + 1, R = r / x;
    while (ll > L) {
      ll--;
      for (auto i : P[ll]) S.insert(make_pair(i, ll));
    }
    while (rr > R) {
      for (auto i : P[rr]) S.erase(make_pair(i, rr));
      rr--;
    }
    if (S.empty()) {
      puts("-1");
      continue;
    }
    int flag = 0;
    int len = P[x].size();
    for (int i = 0; i < len; i++) {
      int a = P[x][i];
      it = S.upper_bound(make_pair(a, 1e9));
      if (it == S.end()) continue;
      int b = (*it).first, y = (*it).second;
      if (x / a * b <= n) {
        printf("%d %d %d %d\n", x, y, x / a * b, y / b * a);
        flag = 1;
        break;
      }
    }
    if (!flag) puts("-1");
  }
  return 0;
}
