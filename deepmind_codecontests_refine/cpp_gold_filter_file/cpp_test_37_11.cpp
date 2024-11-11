#include <bits/stdc++.h>
const long long int M = 1e9 + 7;
using namespace std;
bool ulta(long long int& a1, long long int& a2) { return (a1 > a2); }
long long int fastpow(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2 == 1) res = (res * a) % M;
    a = (a * a) % M;
    n /= 2;
  }
  return res;
}
void run() {
  long long int n, m;
  cin >> n >> m;
  set<long long int> st;
  while (m--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    st.insert(b);
  }
  long long int ind;
  for (long long int i = 1; i < n + 1; i++)
    if (st.count(i) == 0) ind = i;
  for (long long int i = 1; i < n + 1; i++)
    if (i != ind) cout << i << ' ' << ind << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    run();
  }
  return 0;
}
