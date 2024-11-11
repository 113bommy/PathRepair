#include <bits/stdc++.h>
using namespace std;
long long getOnes(const string& s) {
  long long res = 0;
  for (long long i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      ++res;
    }
  }
  return res;
}
void solve() {
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  long long ones1 = getOnes(s1);
  long long ones2 = getOnes(s2);
  if (ones1 % 2 == 0 && ones2 > ones1) {
    cout << "NO\n";
    return;
  }
  if (ones1 % 2 == 1 && ones2 > ones1 + 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(numeric_limits<long double>::digits10 + 1);
  int n = 1;
  for (unsigned long long i = 0; i < n; ++i) {
    solve();
  }
  return 0;
}
