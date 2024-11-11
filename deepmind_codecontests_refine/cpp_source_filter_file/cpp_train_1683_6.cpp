#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  long long K;
  cin >> K;
  K--;
  long long keta = 1;
  long long num = 9;
  long long start = 1;
  int ans = -1;
  while (K) {
    long long use = keta * num;
    if (K >= use) {
      K -= use;
      keta += 1;
      num *= 10;
      start *= 10;
    } else {
      long long place = K / keta;
      long long po = K % keta;
      string st = to_string(start + place);
      ans = st[po] - '0';
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
