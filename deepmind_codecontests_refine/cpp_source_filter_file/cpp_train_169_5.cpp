#include <bits/stdc++.h>
using namespace std;
long long int cn = 1000000000;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long int i, j, m, n, k;
  cin >> n;
  string s;
  cin >> s;
  map<string, long long int> st;
  long long int ans = 0;
  string sa, temp;
  for (i = 1; i < n; i++) {
    temp += s[i - 1];
    temp += s[i];
    st[temp]++;
    if (st[temp] > ans) {
      ans = st[temp];
      sa = temp;
    }
  }
  cout << sa << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, l, t;
  t = 1;
  while (t--) solve();
}
