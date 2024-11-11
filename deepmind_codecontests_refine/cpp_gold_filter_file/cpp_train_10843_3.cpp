#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m = 998244353) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long inverse(long long a, long long m = 998244353) {
  return power(a, m - 2, m);
}
void solve() {
  long long a, b, m;
  cin >> a >> b >> m;
  if (a == b) {
    cout << "1 " << a << endl;
    return;
  }
  int t, n = -1;
  long long pw = 1;
  for (t = 2; t <= 50; t++, pw *= 2) {
    long long mx = (a + m) * pw;
    long long mn = (a + 1) * pw;
    if (mn > b) break;
    if (mn <= b && mx >= b) {
      n = t;
      break;
    }
  }
  if (n == -1) {
    cout << -1 << endl;
    return;
  }
  b -= (a + 1) * pw;
  vector<long long> add;
  pw /= 2;
  while (pw > 0) {
    long long p = min(m - 1, b / pw);
    b -= p * pw;
    add.push_back(p);
    pw /= 2;
  }
  add.push_back(b);
  for (int i = 0; i < add.size(); i++) add[i]++;
  long long curr = a;
  cout << n << ' ';
  cout << curr << ' ';
  long long sum = curr;
  for (int i = 0; i < add.size(); i++) {
    curr = sum + add[i];
    cout << curr << ' ';
    sum += curr;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int Q;
  cin >> Q;
  while (Q--) solve();
}
