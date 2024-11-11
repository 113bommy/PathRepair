#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  set<string> s;
  s.insert("purple");
  s.insert("green");
  s.insert("blue");
  s.insert("orange");
  s.insert("red");
  s.insert("yellow");
  while (n--) {
    string x;
    cin >> x;
    s.erase(x);
  }
  map<string, string> m;
  m["purple"] = "Power";
  m["green"] = "Time";
  m["orange"] = "Soul";
  m["yellow"] = "Mind";
  m["red"] = "Reality";
  m["blue"] = "Space";
  cout << (int)(s).size() << endl;
  for (auto x : s) cout << m[x] << endl;
  return 0;
}
