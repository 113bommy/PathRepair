#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
const long long MOD = (long long)998244353ll;
const long long MAXN = (long long)3e5 + 10;
const long long INF = (long long)2242545357980376863;
const long double EPS = (long double)1e-8;
set<char> st;
string s;
bool check(string t) {
  for (int i = 0, j = t.size() - 1; i < j; i++, j--) {
    if (t[i] != t[j]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  long long n = s.size();
  for (int i = 0; i < n / 2; i++) st.insert(s[i]);
  if (st.size() <= 1) return cout << "Impossible", 0;
  string r = "";
  for (int i = 1; i < n - 1; i++) {
    r = "";
    for (int j = i; j < n; j++) r += s[j];
    for (int j = 0; j < i; j++) r += s[j];
    if (check(r) && s != r) return cout << 1, 0;
  }
  cout << 2;
  return 0;
}
