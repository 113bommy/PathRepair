#include <bits/stdc++.h>
using namespace std;
int cnt[200009];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n;
    map<int, int> aa;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      aa[x] = i;
    }
    string s;
    cin >> s;
    s += "0";
    if (s[0] == '1') cnt[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (s[i - 1] == '1')
        cnt[i] = cnt[i - 1] + 1;
      else
        cnt[i] = cnt[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      if (aa[i] < i) {
        int cn = cnt[i] - cnt[aa[i] - 1];
        if (cn < i - aa[i]) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
}
