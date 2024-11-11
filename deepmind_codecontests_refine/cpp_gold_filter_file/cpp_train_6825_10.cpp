#include <bits/stdc++.h>
using namespace std;
long long sqr(long long first) { return first * first; }
const double PI = acos(-1);
const int MAXN = 1e6 + 10;
const int INF = 1e9;
int n;
int a[MAXN];
int cnt[MAXN];
set<int> g1, have;
void upd(int v, int val) {
  cnt[v] += val;
  if (cnt[v] < 2) g1.erase(v);
  if (cnt[v] == 0) have.erase(v);
}
int ans, s;
int main() {
  ios::sync_with_stdio(0);
  scanf(
      "%d"
      "%d",
      &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    if (cnt[a[i]] == 2) g1.insert(a[i]);
    have.insert(a[i]);
  }
  if (a[s - 1] != 0) {
    upd(a[s - 1], -1);
    cnt[0]++;
    if (cnt[0] == 2) g1.insert(0);
    have.insert(0);
    ans++;
  }
  for (int i = 1; i <= (*have.rbegin()); i++) {
    if (cnt[i] == 0) {
      if (cnt[0] >= 2) {
        upd(0, -1);
        cnt[i] = 1;
        have.insert(i);
      } else {
        int first = *have.rbegin();
        upd(first, -1);
        cnt[i] = 1;
        have.insert(i);
      }
      ans++;
    }
  }
  ans += cnt[0] - 1;
  cout << ans;
}
