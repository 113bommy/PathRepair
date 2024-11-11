#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  map<char, long long int> m;
  long long int cnt = 0;
  map<string, long long int> ma;
  vector<string> v;
  for (long long int i = 1; i < s.size(); i += 1) {
    for (long long int j = 0; j < s.size(); j += 1) {
      string str = s.substr(j, i);
      ma[str]++;
      if (ma[str] > 1 && str.size() == i) {
        v.push_back(str);
      }
    }
  }
  cnt = 0;
  for (long long int i = 0; i < v.size(); i += 1) {
    string str = v[i];
    if (str.size() > cnt) {
      cnt = str.size();
    }
  }
  cout << cnt << endl;
}
