#include <bits/stdc++.h>
const int N = 1e5;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long n;
  long long ans = 0;
  cin >> n;
  if (n == 1) {
    cout << 4 << endl;
  } else if (n == 2) {
    cout << 10 << endl;
  } else if (n == 3) {
    cout << 20 << endl;
  } else if (n == 4) {
    cout << 35 << endl;
  } else if (n == 5) {
    cout << 56 << endl;
  } else if (n == 6) {
    cout << 83 << endl;
  } else if (n == 7) {
    cout << 116 << endl;
  } else if (n == 8) {
    cout << 155 << endl;
  } else if (n == 9) {
    cout << 198 << endl;
  } else if (n == 10) {
    cout << 244 << endl;
  } else if (n == 11) {
    cout << 292 << endl;
  } else {
    ans = 292 + (n - 11) * 49;
    cout << ans << endl;
  }
  return 0;
}
