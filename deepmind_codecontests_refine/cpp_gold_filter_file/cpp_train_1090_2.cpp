#include <bits/stdc++.h>
using namespace std;
long long h, n;
long long get_ans(long long h, long long n, int f) {
  if (h == 0) {
    return 1;
  }
  long long cnt = (1LL << h) / 2;
  if (f == 0) {
    if (n <= cnt) {
      return get_ans(h - 1, n, 1) + 1;
    }
    return get_ans(h - 1, n - cnt, 0) + cnt * 2;
  } else {
    if (n > cnt) {
      return get_ans(h - 1, n - cnt, 0) + 1;
    }
    return get_ans(h - 1, n, 1) + cnt * 2;
  }
}
int main() {
  cin >> h >> n;
  cout << get_ans(h, n, 0) - 1 << endl;
  return 0;
}
