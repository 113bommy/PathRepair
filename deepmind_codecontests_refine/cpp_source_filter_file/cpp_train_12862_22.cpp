#include <bits/stdc++.h>
using namespace std;
string s[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  bool hasGoodPair = false;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (hasGoodPair) continue;
    if (s[i][0] == 'O' && s[i][1] == 'O') {
      hasGoodPair = true;
      s[i][0] = s[i][1] = '+';
    } else if (s[i][2] == 'O' && s[i][3] == 'O') {
      hasGoodPair = true;
      s[i][2] = s[i][3] = '+';
    }
  }
  if (!hasGoodPair)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << s[i] << "\n";
  }
}
