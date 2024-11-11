#include <bits/stdc++.h>
using namespace std;
const int Nn = 6 * 1e5 + 10;
int n, a[Nn], cnt, p[Nn];
long long c[Nn], f[Nn];
vector<pair<int, int> > b;
inline int lowbit(int p) { return p & (-p); }
void add(int p, int x) {
  while (p <= cnt) {
    c[p] += x;
    p += lowbit(p);
  }
}
long long getsum(int p) {
  long long ans = 0;
  while (p > 0) {
    ans += c[p];
    p -= lowbit(p);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d", &a[i]);
    b.push_back(make_pair(a[i], i));
  }
  sort(b.begin(), b.end());
  int len = b.size();
  f[++cnt] = 1;
  a[b[1].second] = cnt;
  for (int i = 1; i < len; i++) {
    if (b[i].first == b[i - 1].first + 1) {
      f[++cnt] = 1;
    } else if (b[i].first > b[i - 1].first + 1) {
      f[++cnt] = b[i].first - b[i - 1].first - 1;
      f[++cnt] = 1;
    }
    a[b[i].second] = cnt;
  }
  for (int i = 1; i <= cnt; i++) p[i] = i;
  for (int i = 1; i <= 2 * n; i += 2) {
    swap(p[a[i]], p[a[i + 1]]);
  }
  long long sum = 0, all = 0;
  for (int i = 1; i <= cnt; i++) {
    sum = sum + (all - getsum(p[i])) * f[p[i]];
    all += f[p[i]];
    add(p[i], f[p[i]]);
  }
  cout << sum;
  return 0;
}
