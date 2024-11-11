#include <bits/stdc++.h>
using namespace std;
const int N = 102;
pair<int, int> ar[N];
bool used[N];
vector<deque<int>> a;
long long binpow(long long a, long long p, long long b) {
  long long n = p;
  long long res = 1;
  while (n) {
    if (n & 1) res = ((res % b) * (a % b)) % b;
    a = (a * a) % b;
    n >>= 1;
  }
  return res;
}
char query(int l1, int r1, int l2, int r2) {
  cout << "! " << (r1 - l1 + 1) << endl;
  for (; l1 <= r1; l1++) cout << l1 << " ";
  cout << endl;
  for (; l2 <= r2; l2++) cout << l2 << " ";
  cout.flush();
  char c;
  cin >> c;
  return c;
}
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
};
int main() {
  fastio();
  int n;
  cin >> n;
  vector<long long> a(n), p(n), s(n), p_i(n), s_i(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 0;
    return 0;
  }
  p[0] = 0;
  p_i[0] = a[0];
  s[n - 1] = 0;
  s_i[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    p_i[i] = max(a[i], p_i[i - 1] + 1);
    p[i] = p_i[i] - a[i] + p[i - 1];
  }
  for (int i = n - 2; i >= 0; --i) {
    s_i[i] = max(a[i], s_i[i + 1] + 1);
    s[i] = s_i[i] - a[i] + s[i + 1];
  }
  long long ans = 1e16;
  for (int i = 0; i < n; i++) {
    long long tmp;
    if (i == 0) {
      tmp = s[i + 1];
      tmp += max(0ll, s_i[i + 1] + 1 - a[i]);
    } else {
      if (i == n - 1) {
        tmp = p[i - 1];
        tmp += max(0ll, p_i[i - 1] + 1 - a[i]);
      } else {
        tmp = s[i + 1] + p[i - 1];
        tmp += max(0ll, max(p_i[i - 1], s_i[i + 1]) + 1 - a[i]);
      }
    }
    if (n == 1) ans = 0;
    ans = min(ans, tmp);
  }
  cout << ans;
  return 0;
}
