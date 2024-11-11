#include <bits/stdc++.h>
using namespace std;
map<string, string> m;
int a, b, c, d;
vector<string> v;
string s, q;
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) {
    cin >> s >> q;
    if (m[s] == "")
      v.push_back(s), m[s] = q, m[q] = s;
    else {
      m[m[s]] = q;
      m[q] = m[s];
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " " << m[v[i]] << endl;
  return 0;
}
