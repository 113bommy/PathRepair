#include <bits/stdc++.h>
using namespace std;
void solve() {}
long long n;
bool alarm[50][100];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    string s;
    cin >> s;
    long long h = 0;
    h += (s[0] - '0') * 10;
    h += (s[1] - '0');
    long long m = 0;
    m += (s[3] - '0') * 10;
    m += (s[4] - '0');
    alarm[h][m] = true;
    if (false) cerr << "setting " << h << " " << m << '\n';
  }
  long long ma = 0;
  long long cur = 0;
  for (long long i = 0; i <= 1e6; i++) {
    long long h = (i / 60) % 24;
    long long m = i % 60;
    if (alarm[h][m]) {
      cur = 0;
    } else {
      cur++;
    }
    ma = max(ma, cur);
  }
  if (false) cerr << ("ma") << " is " << (ma) << '\n';
  long long h = ma / 60;
  long long m = ma % 60;
  if (h < 9) {
    cout << 0;
  }
  cout << h;
  cout << ":";
  if (m < 9) {
    cout << 0;
  }
  cout << m << '\n';
}
