#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long pmp(long long x, long long n) {
  long long a = 1;
  while (n > 0) {
    if (n & 1) a = (a * x) % M;
    x = (x * x) % M;
    n = n >> 1;
  }
  return a;
}
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  if (n <= 2) {
    if (n == 1)
      cout << 1 << endl;
    else if (s == "BB" || s == "AB")
      cout << 0 << endl;
    else
      cout << 2 << endl;
    return;
  }
  stack<char> st;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'A') {
      st.push(s[i]);
      continue;
    }
    if (!st.empty())
      st.pop();
    else
      st.push(s[i]);
  }
  cout << st.size() << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
