#include <bits/stdc++.h>
using namespace std;
struct node {
  long long l, r;
};
bool cmp(node a, node b) {
  if (a.l != b.l) return a.l < b.l;
  return a.r < b.r;
}
long long T, N, S;
node a[200005];
bool can(long long x) {
  long long cnt = 0;
  long long money = 0;
  for (long long i = N; i >= 1; i--) {
    if (a[i].r < x)
      money += a[i].l;
    else if (cnt * 2 > N)
      money += a[i].l;
    else {
      long long pay = max(a[i].l, x);
      money += pay;
      cnt++;
    }
  }
  if (money <= S && cnt * 2 > N) return 1;
  return 0;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> N >> S;
    for (long long i = 1; i <= N; i++) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + N + 1, cmp);
    long long ini = 0;
    long long fin = 1e9;
    while (ini < fin) {
      long long mid = (ini + fin + 1) / 2;
      if (can(mid))
        ini = mid;
      else
        fin = mid - 1;
    }
    cout << ini << "\n";
  }
  return 0;
}
