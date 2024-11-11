#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  map<char, int> m;
  vector<pair<int, char> > v;
  set<char> st;
  cin >> s >> n;
  if (n >= s.size()) return cout << "0", 0;
  if (n == 0) {
    set<char> y;
    for (int i = 0; i < s.size(); ++i) y.insert(s[i]);
    return cout << y.size() << endl << s, 0;
  }
  set<char> ch1;
  for (int i = 0; i < s.size(); ++i) ch1.insert(s[i]);
  if (ch1.size() == 1) return cout << "1" << endl << s[0], 0;
  for (int i = 0; i < s.size(); ++i) m[s[i]]++;
  for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
    v.push_back({it->second, it->first});
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    if (n > 0 && v[i].first <= n) {
      n -= v[i].first;
      v[i].first = 0;
    } else
      break;
  }
  st.clear();
  int b = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].first > 0) {
      st.insert(s[i]);
      ++b;
    }
  }
  cout << b << endl;
  map<char, int> ts;
  for (int i = 0; i < v.size(); ++i) {
    ts[v[i].second] = v[i].first;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (ts[s[i]] > 0) {
      cout << s[i];
      --ts[s[i]];
    }
  }
  cout << endl;
  return 0;
}
