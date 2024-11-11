#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string a;
  cin >> k >> a;
  int ln = a.size();
  vector<int> ones;
  vector<int> zero;
  for (int i = 0; i < ln; i++) {
    if (a[i] == '1') {
      ones.push_back(i);
    } else
      zero.push_back(i);
  }
  if (ones.size() < k)
    puts("0");
  else {
    if (k) {
      int p1 = 0;
      int p2 = k - 1;
      long long ans = 0;
      while (p2 < ones.size()) {
        long long ln1, ln2;
        if (p1 - 1 >= 0)
          ln1 = ones[p1] - ones[p1 - 1];
        else
          ln1 = ones[p1] + 1;
        if (p2 + 1 < ones.size())
          ln2 = ones[p2 + 1] - ones[p2];
        else
          ln2 = ln - ones[p2];
        p1++;
        p2++;
        ln1--;
        ln2--;
        long long by1 = ln1 * ln2;
        long long by2 = ln1 + ln2 + 1;
        ans += by1 + by2;
      }
      cout << ans << endl;
    } else {
      long long cnt = 0;
      long long ans = 0;
      for (int i = 0; i < ln; i++) {
        if (a[i] == '1') {
          ans += (cnt * (cnt + 1)) >> 1;
          cnt = 0;
        } else
          cnt++;
      }
      ans += (1LL * cnt * (cnt + 1)) >> 1;
      cout << ans << endl;
    }
  }
  return 0;
}
