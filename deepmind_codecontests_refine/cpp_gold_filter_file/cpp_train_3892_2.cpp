#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> v(26);
  for (int i = 0; i < s.size(); ++i) {
    v[s[i] - 'a']++;
  }
  int tot = 0;
  for (int i = 0; i < v.size(); ++i) {
    tot += (v[i] % 2);
  }
  cout << ((tot == 0 || tot % 2) ? "First" : "Second") << endl;
  return 0;
}
