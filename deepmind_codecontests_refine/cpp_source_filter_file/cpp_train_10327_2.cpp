#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int k;
  cin >> k;
  for (int q = 0; q < k; ++q) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int incorl = -1, incorf = -1;
    bool suc = 1;
    for (int i = 0; i < n && suc; ++i) {
      if (s[i] != t[i]) {
        if (incorf == -1)
          incorf = i;
        else if (incorl == -1)
          incorl = i;
        else
          suc = 0;
      }
    }
    if (suc && !(incorl != -1 ^ incorf != -1) &&
        (incorf == -1 || (s[incorf] == t[incorl] && s[incorl] == t[incorf])))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
