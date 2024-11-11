#include <bits/stdc++.h>
using namespace std;
long long int fact[200005];
long long int n;
struct point {
  long long int x, y;
};
bool cmp(struct point i1, struct point i2) {
  if (i1.x != i2.x)
    return i1.x < i2.x;
  else {
    return (i1.y < i2.y);
  }
}
long long int fact_(long long int n) {
  long long int ans = 1;
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= n; i++) {
    ans = (ans * i) % 1000000007;
    fact[i] = ans % 1000000007;
  }
  return ans;
}
long long int mod_inv(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b % 2 == 1) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b >> 1;
  }
  return ans;
}
long long int ncr(long long int n, long long int r) {
  if (n < r) return 0;
  if (r == 0) return n;
  if (r == 1) return n;
  if (n == r) return 1;
  return ((((fact[n] % 1000000007) *
            mod_inv(fact[r] % 1000000007, 1000000007 - 2)) %
           1000000007) *
          mod_inv(fact[n - r] % 1000000007, 1000000007 - 2)) %
         1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<struct point> ar1(4), ar2(4);
  for (int i = 0; i < 4; i++) {
    long long int a, b;
    cin >> a >> b;
    ar1[i].x = a;
    ar1[i].y = b;
  }
  for (int i = 0; i < 4; i++) {
    long long int a, b;
    cin >> a >> b;
    ar2[i].x = a;
    ar2[i].y = b;
  }
  sort(ar1.begin(), ar1.end(), cmp);
  sort(ar2.begin(), ar2.end(), cmp);
  bool f = 0;
  for (int i = 0; i < 4; i++) {
    if (ar2[i].x >= ar1[0].x && ar2[i].y >= ar1[0].y && ar2[i].x <= ar1[3].x &&
        ar2[i].y <= ar1[3].y)
      f = 1;
  }
  for (int i = 0; i < 4; i++) {
    if ((ar1[i].x + ar1[i].y) >= (ar2[1].x + ar2[1].y) &&
        (ar1[i].y - ar1[i].x) >= (ar2[1].y - ar2[1].x) &&
        (ar1[i].x + ar1[i].y) <= (ar2[2].x + ar2[2].y) &&
        (ar1[i].y - ar1[i].x) <= (ar2[2].y - ar2[2].x))
      f = 1;
  }
  point c1, c2;
  c1.x = (ar1[0].x + ar1[0].x) / 2;
  c1.y = (ar1[0].y + ar1[3].y) / 2;
  c2.x = (ar2[0].x + ar2[0].x) / 2;
  c2.y = (ar2[0].y + ar2[3].y) / 2;
  if (c2.x >= ar1[0].x && c2.y >= ar1[0].y && c2.x <= ar1[3].x &&
      c2.y <= ar1[3].y)
    f = 1;
  if ((c1.x + c1.y) >= (ar2[1].x + ar2[1].y) &&
      (c1.y - c1.x) >= (ar2[1].y - ar2[1].x) &&
      (c1.x + c1.y) <= (ar2[2].x + ar2[2].y) &&
      (c1.y - c1.x) <= (ar2[2].y - ar2[2].x))
    f = 1;
  if (!f)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
  }
}
