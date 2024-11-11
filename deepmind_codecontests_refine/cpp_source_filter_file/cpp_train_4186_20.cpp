#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test_case;
  cin >> test_case;
  while (test_case--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    int c = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') c++;
    }
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') break;
      l++;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') break;
      r--;
    }
    int ans = max(max(max(int(n + c), max(int(r) * 2, int(n - l) * 2)),
                      int(abs(r - l + 1)) + max(int(n - l), int(r))),
                  int(n + r - l + 1) - min(int(l + 1), int(n - r - 1)));
    cout << ans << endl;
  }
  return 0;
}
