#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int k;
  cin >> k;
  vector<int> w(26);
  for (int i = 0; i < 26; i++) {
    cin >> w[i];
  }
  vector<int> ws(s.size());
  for (int i = 0; i < s.size(); i++) {
    ws[i] = w[s[i] - 'a'];
  }
  int mc = *max_element(w.begin(), w.end());
  int ans = 0;
  for (int i = 0; i < ws.size(); i++) {
    ans += ws[i] * (i + 1);
  }
  ans += mc * (ws.size() + 1 + ws.size() + k) * k / 2;
  cout << ans << endl;
}
