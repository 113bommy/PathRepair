#include <bits/stdc++.h>
using namespace std;
int main() {
  string key, value;
  map<string, string> m;
  map<string, string> m2;
  int t;
  cin >> t;
  while (t--) {
    cin >> key >> value;
    auto it = m2.find(key);
    if (it != m2.end()) {
      m[it->second] = value;
      m2[value] = it->second;
    } else {
      m[key] = value;
      m2[value] = key;
    }
  }
  cout << m.size() << endl;
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
}
