#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, q;
  cin >> s >> q;
  int curr = 0;
  int n = q.length();
  for (int i = 0; i < n; i++) {
    if (s[curr] == q[i]) curr++;
  }
  cout << curr + 1;
}
