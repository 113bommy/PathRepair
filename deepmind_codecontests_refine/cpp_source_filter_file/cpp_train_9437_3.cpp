#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mp;
  string s;
  int size;
  cin >> s;
  size = s.size();
  set<char> st;
  for (int i = 0; i < size; i++) {
    mp[s[i]]++;
    st.insert(s[i]);
  }
  int sz_st = st.size();
  if (sz_st == 1) {
    cout << "NO\n";
    return 0;
  }
  if (sz_st == 4) {
    cout << "YES\n";
    return 0;
  }
  if (sz_st == 2) {
    for (auto x : st) {
      if (mp[x] == 1) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    return 0;
  }
  if (sz_st == 3) {
    int cnt = 0;
    for (auto x : st) {
      if (mp[x] > 1) cnt++;
    }
    if (cnt >= 1) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
