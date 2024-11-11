#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first < b.first || (a.first == b.first && a.second < b.second));
}
int main() {
  map<string, string> thanosoclz;
  int n;
  thanosoclz["red"] = "Reality";
  thanosoclz["yellow"] = "Mind";
  thanosoclz["orange"] = "Soul";
  thanosoclz["blue"] = "Space";
  thanosoclz["green"] = "Time";
  thanosoclz["purple"] = "Power";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    thanosoclz[s] = "0";
  }
  cout << 6 - n;
  map<string, string>::iterator it;
  for (it = thanosoclz.begin(); it != thanosoclz.end(); it++) {
    if (it->second != "0") cout << it->second;
    cout << endl;
  }
}
