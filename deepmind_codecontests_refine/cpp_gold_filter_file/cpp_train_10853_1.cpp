#include <bits/stdc++.h>
using namespace std;
int tc = 1;
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " ";
  err(++it, args...);
}
const int M = 1e9 + 7;
const long long Inf = (long long)2e18 + 5;
const int N = 2e5 + 5;
long long vis[N], res[N];
bool isPr(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "FastestFinger" << endl;
  } else if (n % 2 == 0 && isPr(n / 2)) {
    cout << "FastestFinger" << endl;
  } else if (n > 2 && (!(n & (n - 1)))) {
    cout << "FastestFinger" << endl;
  } else {
    cout << "Ashishgup" << endl;
  }
  return 0;
}
int main() {
  int test = 1;
  scanf("%d", &test);
  while (test--) solve();
  return 0;
}
