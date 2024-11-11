#include <bits/stdc++.h>
using namespace std;
char c[] = "RGB";
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n, k;
    cin >> n >> k;
    int ans = 2001;
    string s;
    cin >> s;
    for (int z = 0; z < 3; z++) {
      int count = 0;
      for (int i = 0; i < k; i++) {
        if (s[i] != c[(i + z) % 3]) count++;
      }
      ans = min(ans, count);
      for (int i = k; i < n; i++) {
        if (s[i] != c[(i + z) % 3]) count++;
        if (s[i - k] != c[(i + z - k) % 3]) count--;
        ans = min(ans, count);
      }
    }
    cout << ans << endl;
  }
}
