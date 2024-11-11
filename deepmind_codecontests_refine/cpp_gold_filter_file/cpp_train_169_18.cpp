#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  int n;
  cin >> n;
  cin >> s;
  string ans = "";
  int ans_rep = 0;
  for (int i = 0; i < n - 1; i++) {
    string gram2 = s.substr(i, 2);
    int rep = 0;
    for (int j = 0; j < n - 1; j++) {
      if (gram2 == s.substr(j, 2)) rep++;
    }
    if (rep > ans_rep) {
      ans = gram2;
      ans_rep = rep;
    }
  }
  cout << ans << endl;
  return 0;
}
