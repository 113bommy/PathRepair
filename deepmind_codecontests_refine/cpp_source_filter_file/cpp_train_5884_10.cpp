#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  intmax_t a, b, ans = 0;
  cin >> a >> b;
  vector<intmax_t> nozero;
  for (intmax_t i = 1; (1LL << i) - 1 <= 1e18; ++i) {
    nozero.push_back((1LL << i) - 1);
  }
  for (intmax_t i : nozero) {
    int digits = 0;
    intmax_t temp = i;
    while (temp) {
      digits++;
      temp = temp >> 1;
    }
    for (int j = 0; j < digits - 1; ++j) {
      if (i - (1LL << j) >= a && i - (1LL << j) <= b) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
