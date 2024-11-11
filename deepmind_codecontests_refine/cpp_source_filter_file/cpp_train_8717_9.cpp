#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> s1, s2, s;
  int n;
  string k;
  cin >> n;
  s1.push_back("purple");
  s2.push_back("Power");
  s1.push_back("green");
  s2.push_back("Time");
  s1.push_back("blue");
  s2.push_back("Space");
  s1.push_back("orange");
  s2.push_back("Soul");
  s1.push_back("red");
  s2.push_back("Reality");
  s1.push_back("yellow");
  s2.push_back("mind");
  while (n--) {
    cin >> k;
    for (int i = 0; i < 6; i++) {
      if (k == s1[i]) {
        s1.erase(s1.begin() + i);
        s2.erase(s2.begin() + i);
      }
    }
  }
  cout << s2.size() << endl;
  for (int i = 0; i < s2.size(); i++) {
    cout << s2[i] << endl;
  }
}
