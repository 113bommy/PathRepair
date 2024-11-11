#include <bits/stdc++.h>
using namespace std;
long long l, s[3], dp3[300001], dp2[300001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s[0] >> s[1] >> s[2] >> l;
  for (int i = 0; i <= l; i++) {
    dp3[i] = i + 1 + dp3[i - 1];
    dp2[i] = i + 1;
  }
  for (int i = 1; i <= l; i++) {
    dp3[i] += dp3[i - 1];
    dp2[i] += dp2[i - 1];
  }
  for (int j = 0; j < 3; j++) {
    swap(s[0], s[j]);
    for (int i = 0; i <= l; i++) {
      long long a = s[0] + i;
      long long b = s[1] + s[2];
      if (a - b >= 0) {
        dp3[l] -= dp2[min(a - b, l - i)];
      }
    }
    swap(s[0], s[j]);
  }
  cout << dp3[l] << "\n";
  return 0;
}
