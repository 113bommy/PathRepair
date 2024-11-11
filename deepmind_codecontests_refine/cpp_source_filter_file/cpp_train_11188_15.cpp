#include <bits/stdc++.h>
using namespace std;
void solve() {
  string name, handle;
  int req;
  cin >> req;
  map<string, string> mp1;
  map<string, string> temp;
  for (int i = 0; i < 5; i++) {
    cin >> name >> handle;
    if (mp1.find(name) == mp1.end() and temp.find(name) == temp.end()) {
      mp1.insert(pair<string, string>(name, handle));
      temp.insert(pair<string, string>(handle, name));
    } else if (mp1.find(name) == mp1.end() and temp.find(name) != temp.end()) {
      string str = temp[name];
      mp1[str] = handle;
      temp.erase(name);
      temp.insert(pair<string, string>(handle, str));
    }
  }
  cout << mp1.size() << endl;
  map<string, string>::iterator it;
  for (it = mp1.begin(); it != mp1.end(); it++)
    cout << it->first << " " << it->second << endl;
  return;
}
int main() {
  solve();
  return 0;
}
