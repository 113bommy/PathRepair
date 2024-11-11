#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  vector<int> a(3);
  int l;
  cin >> a[0] >> a[1] >> a[2] >> l;
  long long int ans = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i <= l; i++) {
    int h = (a[0] + a[1] + a[2] + i - 1) / 2;
    if (a[2] > h) continue;
    ans += (i + 1LL) * (i + 2LL) / 2LL;
    for (int j = 0; j < 3; j++) {
      if (a[j] + i > h) {
        long long int remainder = a[j] + i - (h + 1);
        ans -= (remainder + 2LL) * (remainder + 1LL) / 2LL;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
