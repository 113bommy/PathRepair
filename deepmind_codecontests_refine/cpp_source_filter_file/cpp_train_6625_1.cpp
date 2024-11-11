#include <bits/stdc++.h>
using namespace std;
vector<int> v[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s1, s2;
  int i, ans = 0, id = -1;
  cin >> s1 >> s2;
  for (i = 0; i < s1.size(); i++) {
    v[s1[i] - 'a'].push_back(i);
  }
  for (i = 0; i < s2.size(); i++) {
    if (v[s2[i] - 'a'].empty()) {
      cout << "-1\n";
      return 0;
    }
    if (v[s2[i] - 'a'][v[s2[i] - 'a'].size() - 1] < id) {
      id = -1;
      ans++;
    }
    int x = upper_bound(v[s2[i] - 'a'].begin(), v[s2[i] - 'a'].end(), id) -
            v[s2[i] - 'a'].begin();
    id = v[s2[i] - 'a'][x];
  }
  cout << ans + 1 << endl;
  return 0;
}
