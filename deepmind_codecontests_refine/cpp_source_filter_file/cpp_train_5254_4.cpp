#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 100;
int last[MN];
int cnt[MN];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    cnt[t]++;
  }
  int ls = -1;
  for (int i = 0; i < MN; i++) {
    last[i] = ls;
    if (cnt[i]) {
      ls = i;
    }
  }
  int ans = 0;
  for (int i = 1; i < MN; i++) {
    if (cnt[i]) {
      for (int j = 2 * i; j < MN; j += i) {
        if (last[j] != -1) {
          ans = max(ans, last[j] % i);
        }
      }
    }
  }
  cout << ans;
}
