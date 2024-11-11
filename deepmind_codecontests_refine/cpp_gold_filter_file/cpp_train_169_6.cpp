#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s, s1;
  map<string, int> make_pair;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    string a;
    a.push_back(s[i]);
    a.push_back(s[i + 1]);
    make_pair[a]++;
  }
  int ma = 0;
  for (auto& i : make_pair) {
    if (i.second > ma) {
      ma = i.second;
      s1 = i.first;
    }
  }
  cout << s1;
}
