#include <bits/stdc++.h>
using namespace std;
int main() {
  int sk1 = 0;
  string s;
  map<char, long long> sk;
  cin >> s;
  for (auto c : s) {
    sk[c]++;
  }
  for (auto p : sk) {
    sk1 += p.second * p.second;
  }
  cout << sk1;
  return 0;
}
