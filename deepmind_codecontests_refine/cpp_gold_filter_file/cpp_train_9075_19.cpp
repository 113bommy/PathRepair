#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  map<char, int> mp;
  for (int i = 0; i < str.size(); i++) {
    mp[str[i]]++;
  }
  if (mp['4'] == 0 && mp['7'] == 0)
    cout << -1 << endl;
  else if (mp['4'] >= mp['7'])
    cout << 4 << endl;
  else
    cout << 7 << endl;
  return 0;
}
