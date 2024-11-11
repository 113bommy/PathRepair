#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  map<string, string> m;
  for (int i = 0; i < b; i++) {
    string s, ss;
    cin >> s >> ss;
    pair<string, string> p1(s, ss);
    m.insert(p1);
  }
  for (int i = 0; i < a; i++) {
    string temp;
    cin >> temp;
    map<string, string>::iterator it = m.find(temp);
    int temp1 = (*it).first.size();
    int temp2 = (*it).second.size();
    if (temp1 > temp2)
      cout << (*it).second;
    else
      cout << (*it).first;
    if (i != a - 1) cout << " ";
  }
  cout << endl;
}
