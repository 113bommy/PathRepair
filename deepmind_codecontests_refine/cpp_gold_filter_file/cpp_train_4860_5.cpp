#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long ct = 0;
  string s;
  cin >> n;
  vector<vector<long long>> a(300001, vector<long long>(2, 0));
  for (int i = 0; i < n; i++) {
    cin >> s;
    int cto = 0, ctc = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '(')
        cto++;
      else {
        if (cto > 0)
          cto--;
        else
          ctc++;
      }
    }
    if (cto && ctc) continue;
    if (cto == 0 && ctc == 0)
      ct++;
    else {
      if (cto)
        a[cto][0]++;
      else
        a[ctc][1]++;
    }
  }
  long long ans = ct * ct;
  for (int i = 1; i <= 300000; i++) ans += (a[i][0] * a[i][1]);
  cout << ans << endl;
  return 0;
}
