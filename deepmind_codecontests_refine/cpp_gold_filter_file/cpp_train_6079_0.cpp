#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, l, r, co = 0, qa;
  string s;
  cin >> s;
  cin >> q;
  char c = 'a';
  int in = 0;
  vector<long long> v;
  for (char i : s) {
    if (i == c) co++;
    c = i;
    v.push_back(co);
  }
  v.push_back(co);
  v.erase(v.begin());
  while (q--) {
    cin >> l >> r;
    qa = v[r - 2];
    if (l > 1) qa -= v[l - 2];
    cout << qa << endl;
  }
  return 0;
}
