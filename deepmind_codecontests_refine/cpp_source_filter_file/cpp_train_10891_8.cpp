#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 5;
int res0, res1;
int ask(string s) {
  cout << "? " << s << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}
int ans0 = -1;
int ans1 = -1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string buf(n, '0');
  res0 = ask(buf);
  buf.front() = '1';
  res1 = ask(buf);
  if (res1 < res0) {
    ans1 = 0;
  } else {
    ans0 = 0;
  }
  int lo = 1;
  int hi = n;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    string buf(n, '1');
    for (int i = lo; i < mid; i++) {
      buf[i] = '0';
    }
    int res = ask(buf);
    int len = mid - lo;
    if (ans0 == -1) {
      int diff = res - res1;
      if (diff != len) {
        hi = mid;
      } else {
        lo = mid;
      }
    } else if (ans1 == -1) {
      int diff = res1 - res;
      if (diff != len) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
  }
  if (ans1 == -1)
    ans1 = lo;
  else
    ans0 = lo;
  cout << "! " << ans0 + 1 << " " << ans1 + 1 << endl;
  return 0;
}
