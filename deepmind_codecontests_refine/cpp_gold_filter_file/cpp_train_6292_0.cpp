#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int idx = i;
    char mx = s[i];
    for (int j = i; j < (i + k + 1) && j < n; ++j) {
      if (mx < s[j]) {
        mx = s[j];
        idx = j;
      }
    }
    for (int j = idx; j > i; j--) {
      swap(s[j], s[j - 1]);
    }
    k = k + i - idx;
    if (k <= 0) break;
  }
  cout << s << '\n';
  return 0;
}
