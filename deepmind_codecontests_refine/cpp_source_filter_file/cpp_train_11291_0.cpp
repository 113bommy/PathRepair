#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
map<int, long long> m1, m2, ans;
map<int, long long>::iterator it1, it2;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve(int l, int r) {
  if (l == r) {
    ans[a[l]]++;
    return;
  }
  int mid = l + r >> 1;
  m1.clear();
  m2.clear();
  int lgcd = 0, rgcd = 0;
  for (int i = mid; i >= l; i--) m1[lgcd = gcd(lgcd, a[i])]++;
  for (int i = mid + 1; i <= r; i++) m2[rgcd = gcd(rgcd, a[i])]++;
  for (it1 = m1.begin(); it1 != m1.end(); ++it1)
    for (it2 = m2.begin(); it2 != m2.end(); ++it2) {
      ans[gcd(it1->first, it2->first)] += (it1->second) * (it2->second);
    }
  solve(l, mid);
  solve(mid + 1, r);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  solve(1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", ans[x]);
  }
}
