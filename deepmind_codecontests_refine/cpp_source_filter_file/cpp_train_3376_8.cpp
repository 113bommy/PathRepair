#include <bits/stdc++.h>
using namespace std;
long long int mnof(long long int cnt, long long int pos) {
  long long int mxcnt = cnt % pos;
  long long int mn = cnt / pos;
  long long int mx = mn + 1;
  return mxcnt * mx * mx + (pos - mxcnt) * mn * mn;
}
long long int mxof(long long int cnt, long long int pos) {
  cnt -= pos - 1;
  return pos - 1 + cnt * cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int a, b;
  cin >> a >> b;
  if (a == 0) {
    cout << -b * b << endl;
    for (int i = 0; i < b; i++) cout << 'x';
    cout << endl;
    return 0;
  }
  if (b == 0) {
    cout << a * a << endl;
    for (int i = 0; i < a; i++) cout << 'o';
    cout << endl;
    return 0;
  }
  long long int SCORE = -85LL * 1000 * 1000 * 1000 * 1000;
  long long int ans;
  for (long long int i = 1; i <= min(b - 1, a); i++) {
    long long int val = mxof(a, i) - mnof(b, i + 1);
    if (val >= SCORE) {
      SCORE = val;
      ans = i;
    }
  }
  cout << SCORE << '\n';
  long long int cnt = b % (ans + 1);
  for (int i = 0; i < ans; i++) {
    for (int j = 0; j < b / (ans + 1) + bool(cnt); j++) cout << 'x';
    if (cnt) cnt--;
    cout << 'o';
  }
  a -= ans;
  for (int i = 0; i < a; i++) cout << 'o';
  for (int i = 0; i < b / (ans + 1); i++) cout << 'x';
  cout << endl;
  return 0;
}
