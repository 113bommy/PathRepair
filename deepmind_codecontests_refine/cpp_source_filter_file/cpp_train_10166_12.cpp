#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int64_t, int64_t> &a,
               const pair<int64_t, int64_t> &b) {
  return (a.second < b.second);
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void show_vec(vector<int64_t> &v) {
  for (int64_t i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
bool resolve(int64_t n, int64_t p) {
  for (int64_t i = 2; i <= (max((int64_t)sqrt(n), (int64_t)p));) {
    if (!(n % i)) return false;
    if (i == 2)
      i = 3;
    else
      i += 2;
  }
  return true;
}
void solve() {
  int64_t p, n, i;
  cin >> p >> n;
  if (!(n % 2)) n--;
  for (i = n; i > p; i -= 2)
    if (resolve(i, p)) {
      cout << i << endl;
      return;
    }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
