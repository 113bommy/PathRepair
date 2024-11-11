#include <bits/stdc++.h>
using namespace std;
int main() {
  int s[6], ans = 0;
  ios::sync_with_stdio(false);
  for (int i = 0; i < 6; ++i) cin >> s[i];
  bool did = true;
  while (did) {
    did = false;
    for (int i = 0; i < 6; ++i) {
      if (s[(i - 1) % 6] > 1 && s[(i + 1) % 6] > 1) {
        ans += s[i] * 2 + 1;
        ++s[i];
        --s[(i - 1) % 6];
        --s[(i + 1) % 6];
        did = true;
      }
    }
  }
  for (int i = 0; i < 6; ++i) {
    if (s[i] > 1) {
      ans += s[i] * 4 + 2;
      goto out;
    }
  }
  ans += 6;
out:
  cout << ans << endl;
  return 0;
}
