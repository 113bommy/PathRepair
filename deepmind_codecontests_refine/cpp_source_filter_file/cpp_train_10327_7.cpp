#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s == t) {
      cout << "No\n";
      continue;
    }
    vector<int> idc;
    for (int i = 0; i < n; i++)
      if (s[i] != t[i]) idc.push_back(i);
    int n1 = idc.size();
    if (n1 > 2) {
      cout << "No\n";
      continue;
    }
    int i1 = idc[0], i2 = idc[1];
    if (s[i1] == s[i2] && t[i1] == t[i2])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
