#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int j = 0;
  for (int i = 0; i < s.size() && j < 26; i++) {
    if (s[i] <= 'a' + j) {
      s[i] = 'a' + j;
      j++;
    }
  }
  if (j == 26)
    cout << s << endl;
  else
    cout << -1 << endl;
}
