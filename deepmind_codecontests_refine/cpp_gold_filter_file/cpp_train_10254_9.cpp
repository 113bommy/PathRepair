#include <bits/stdc++.h>
using namespace std;
long long int pw[200005];
void initial() {
  pw[0] = 1;
  for (long long int i = 1; i < 200005; i++) {
    pw[i] = (31 * pw[i - 1]) % 1000000007;
  }
}
string s1, s2;
string string1(string s1) {
  if (s1.size() % 2 == 1) {
    return s1;
  }
  string t1, t2;
  t1 = "", t2 = "";
  for (long long int i = 0; i < s1.size() / 2; i++) {
    t1 += s1[i];
  }
  for (long long int i = s1.size() / 2; i < s1.size(); i++) {
    t2 += s1[i];
  }
  t1 = string1(t1);
  t2 = string1(t2);
  if (t1 < t2) {
    return (t1) + (t2);
  } else {
    return (t2) + (t1);
  }
}
inline void solve() {
  initial();
  cin >> s1 >> s2;
  if (string1(s1) == string1(s2)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1;
  while (tests--) {
    solve();
  }
}
