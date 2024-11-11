#include <bits/stdc++.h>
using namespace std;
struct rc {
  int a, b, num, first_num;
};
rc a[200000];
bool cmp1(rc a, rc b) { return (a.b < b.b || (a.b == b.b && a.a > b.a)); }
bool cmp2(rc a, rc b) { return (a.a > b.a || (a.a == b.a && a.num > b.num)); }
bool cmp3(rc a, rc b) { return (a.b < b.b); }
int main() {
  ios_base::sync_with_stdio(0);
  int n, p, k;
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b;
  for (int i = 1; i <= n; i++) a[i].first_num = i;
  sort(a + 1, a + n + 1, cmp1);
  for (int i = 1; i <= n; i++) a[i].num = i;
  sort(a + p - k + 1, a + n + 1, cmp2);
  int mx = n + 1;
  for (int i = p - k + 1; i <= p; i++) {
    mx = min(mx, a[i].num);
    cout << a[i].first_num << " ";
  }
  sort(a + 1, a + n + 1, cmp1);
  mx--;
  assert(mx >= p - k);
  sort(a + 1, a + mx + 1, cmp3);
  for (int i = mx; i >= mx - (p - k) + 1; i--) cout << a[i].first_num << " ";
  cout << endl;
  return 0;
}
