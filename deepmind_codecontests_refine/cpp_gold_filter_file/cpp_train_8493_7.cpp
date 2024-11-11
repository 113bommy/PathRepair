#include <bits/stdc++.h>
using namespace std;
const long long max_n = 300011, log_n = 32, max_m = 111, mod = 1000000007,
                inf = 1011111111111111111LL, p = 1009, p2 = 997;
int n, k, l, r;
int get_ans(int l, int r) {
  if (l == r) {
    return l;
  }
  if (l + 1 == r) {
    cout << "1 " << l << " " << r << endl;
    fflush(stdout);
    string res;
    cin >> res;
    if (res[0] == 'T') {
      return l;
    }
    return r;
  }
  if (l + 2 == r) {
    cout << "1 " << l << " " << r << endl;
    fflush(stdout);
    string res;
    cin >> res;
    if (res[0] != 'T') {
      return r;
    }
    return get_ans(l, l + 1);
  }
  int mid1 = (l * 2 + r + 1) / 3;
  int mid2 = (l + r * 2 + 1) / 3;
  int mid3 = (mid1 + mid2) / 2;
  cout << "1 " << mid1 << " " << mid2 << endl;
  fflush(stdout);
  string res;
  cin >> res;
  if (res[0] == 'T') {
    return get_ans(l, mid3);
  }
  return get_ans(mid3, r);
}
int main() {
  cin >> n >> k;
  l = 1;
  r = n;
  int res = get_ans(l, r);
  int res1;
  if (res > 1)
    res1 = get_ans(l, res - 1);
  else {
    res1 = get_ans(res + 1, r);
    cout << "2 " << res << " " << res1 << endl;
    return 0;
  }
  if (res1 == res - 1) {
    cout << "1 " << res1 << " " << res << endl;
    fflush(stdout);
    string ff;
    cin >> ff;
    if (ff[0] == 'N') {
      res1 = get_ans(res + 1, r);
    }
  }
  cout << "2 " << res << " " << res1 << endl;
  return 0;
}
