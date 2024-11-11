#include <bits/stdc++.h>
using namespace std;
bool isHere(set<string> s, string str) { return s.find(str) != s.end(); }
int main() {
  long long n;
  cin >> n;
  vector<string> msgs;
  set<string> names;
  vector<string> list;
  string temp;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    msgs.push_back(temp);
  }
  for (long long i = n - 1; i >= 0; i--)
    if (names.find(msgs[i]) != names.end()) {
      list.push_back(msgs[i]);
      names.insert(msgs[i]);
    }
  cout << endl;
  for (long long i = 0; i < list.size(); i++) cout << list[i] << endl;
  return 0;
}
