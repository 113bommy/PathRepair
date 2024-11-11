#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, cnt = 0;
    string s1, s2;
    cin >> n >> s1;
    s2 = s1;
    sort(s1.begin(), s1.end());
    for (i = 0; i < n; i++) {
      if (s1[i] != s2[i]) cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
