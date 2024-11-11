#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using VL = vector<LL>;
using VI = vector<int>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using PII = pair<int, int>;
void _print() {}
template <typename T, typename... Args>
void _print(const T first_elem, const Args... args) {}
int main() {
  string s;
  cin >> s;
  map<char, int> mp_;
  for (auto ch : s) {
    if (ch == '4' || ch == '7') mp_[ch]++;
  }
  if (mp_.count('4') == 0 || mp_.count('7') == 0)
    cout << "-1" << endl;
  else if (mp_['4'] >= mp_['7'])
    cout << "4" << endl;
  else
    cout << "7" << endl;
  return 0;
}
