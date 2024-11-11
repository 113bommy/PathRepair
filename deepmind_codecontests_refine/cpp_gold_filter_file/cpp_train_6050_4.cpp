#include <bits/stdc++.h>
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long pw(long long a, long long b) {
  return (!b ? 1 : (b & 1 ? a * pw(a * a, b / 2) : pw(a * a, b / 2)));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s >> s;
  sort((s).begin(), (s).end());
  cout << s << endl;
  return 0;
}
