#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int l1 = s.length();
  int l2 = t.length();
  vector<int> begin;
  vector<int> end(l2);
  int j = 0;
  for (int i = 0; i < l1; i++) {
    if (t[j] == s[i]) {
      begin.push_back(i);
      j++;
    }
    if (j == l2) break;
  }
  j = l2 - 1;
  for (int i = l1 - 1; i >= 0; i--) {
    if (t[j] == s[i]) {
      end[j] = i;
      j--;
    }
    if (j == -1) break;
  }
  int ans = 0;
  for (int i = 0; i < l2 - 1; i++) {
    ans = max(ans, end[i + 1] - begin[i] - 1);
  }
  ans = max(end[0], ans);
  ans = max(l1 - 1 - begin[l2 - 1], ans);
  cout << ans;
}
