#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 + c - '0';
  return x;
}
const int maxn = 100007;
int n, tt;
pair<int, int> a[maxn];
vector<pair<int, int> > ans;
void input() {
  n = rd();
  for (int i = 1, _ = n; i <= _; i++) {
    a[i].first = rd();
    a[i].second = i;
    if (!a[i].first) tt++;
  }
}
inline bool cmp(const pair<int, int> a, const pair<int, int> b) {
  return a.first == b.first ? a.second < b.second : a.first > b.first;
}
inline bool opr(pair<int, int> *a) {
  sort(a + 1, a + 4, cmp);
  if (!a[3].first) return 1;
  if (a[1] == a[2]) {
    ans.push_back(pair<int, int>(a[1].second, a[2].second));
    swap(a[2], a[3]);
    return 1;
  } else if (a[2] == a[3]) {
    ans.push_back(pair<int, int>(a[2].second, a[3].second));
    return 1;
  }
  int c = a[3].first;
  int p = a[2].first / a[3].first;
  for (int i = 0; (1 << i) <= p; i++) {
    if (p >> i & 1)
      a[2].first -= (1 << i) * c,
          ans.push_back(pair<int, int>(a[2].second, a[3].second));
    else
      a[1].first -= (1 << i) * c,
          ans.push_back(pair<int, int>(a[1].second, a[3].second));
    a[3].first += (1 << i) * c;
  }
  swap(a[2], a[3]);
  return a[3].first == 0;
}
void solve() {
  if (tt >= n - 1) {
    puts("-1");
    return;
  } else if (tt == n - 2) {
    puts("0");
    return;
  }
  for (int i = n - 2, _ = 1; i >= _; i--) {
    while (!opr(a + i - 1))
      ;
  }
  printf("%d\n", (int)ans.size());
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
}
int main() {
  input();
  solve();
  return 0;
}
