#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int fp(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int x = fp(a, b / 2);
  x = (x * x) % 1000000007;
  if (b & 1) x = (x * a) % 1000000007;
  return x;
}
void c_p_c() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
}
bool isPalin(string s) {
  long long int i = 0, j = s.length() - 1;
  while (i < j) {
    if (s[i++] != s[j--]) return false;
  }
  return true;
}
signed main() {
  c_p_c();
  string s;
  cin >> s;
  string t;
  for (long long int i = 0; i < s.size(); i++) {
    t = s;
    t.insert(i, "a");
    t[i] = t[s.size() - i];
    if (isPalin(t)) {
      cout << t << "\n";
      return 0;
    }
  }
  cout << "NA"
       << "\n";
}
