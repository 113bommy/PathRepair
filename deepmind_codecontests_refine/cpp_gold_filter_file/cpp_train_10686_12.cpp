#include <bits/stdc++.h>
using namespace std;
long long get_ans(long long n, long long k) {
  while (true) {
    if (k % 2 == 0) {
      return k / 2 + 1;
    }
    long long cnt = (k / 2 + 1);
    k += n - cnt;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    long long pos = 0;
    cin >> pos;
    --pos;
    cout << get_ans(n, pos) << endl;
  }
  return 0;
}
