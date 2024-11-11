#include <bits/stdc++.h>
using namespace std;
vector<char> v;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  long long i, kol = 0, t;
  cin >> s;
  while (kol < s.size()) {
    t = v.size();
    if (t == 0 || v[t - 1] != s[kol])
      v.push_back(s[kol]);
    else
      v.pop_back();
    kol++;
  }
  if (v.size()) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
