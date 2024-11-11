#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
set<char> st;
map<char, int> mp1;
map<char, int> mp2;
int main() {
  string second, t;
  cin >> second >> t;
  int l = 0;
  if (second.size() > t.size()) l = 1;
  for (auto x : second) {
    st.insert(x);
    mp1[x]++;
  }
  int l1 = st.size();
  for (auto x : t) {
    st.insert(x);
    mp2[x]++;
  }
  int l2 = st.size();
  if (l1 != l2 or t.size() > second.size()) {
    cout << "need tree";
    return 0;
  } else {
    for (auto x : t) {
      if (mp1[x] < mp2[x]) {
        cout << "need tree";
        return 0;
      }
    }
  }
  int j = 1;
  int d = 0, p;
  for (auto x : t) {
    for (int i = j - 1; i < second.size(); i++) {
      j++;
      if (second[i] == x) {
        d++;
        break;
      } else
        continue;
    }
  }
  if (d == t.size())
    p = 0;
  else
    p = 1;
  if (l == 1 and p == 1) {
    cout << "both";
    return 0;
  } else if (l == 1 and p == 0) {
    cout << "automaton";
    return 0;
  } else if (l == 0 and p == 1) {
    cout << "array";
    return 0;
  }
  return 0;
}
