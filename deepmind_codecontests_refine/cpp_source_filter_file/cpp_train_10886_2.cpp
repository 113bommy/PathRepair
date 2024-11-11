#include <bits/stdc++.h>
using namespace std;
const long long inf = LONG_MAX;
const long long arr = 1000000;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
bool check(set<char> st) {
  if (st.size() > 2 || st.size() <= 1) return true;
  vector<char> v;
  for (auto first : st) v.push_back(first);
  if (v[0] == 'L' && v[1] == 'R') return false;
  if (v[0] == 'R' && v[1] == 'L') return false;
  if (v[0] == 'U' && v[1] == 'D') return false;
  if (v[0] == 'U' && v[1] == 'D') return false;
  return true;
}
int main(void) {
  long long n;
  cin >> n;
  string second;
  cin >> second;
  set<char> st;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    st.insert(second[i]);
    if (st.size() <= 2 && check(st) == true)
      continue;
    else {
      st.clear();
      ans++;
      st.insert(second[i]);
    }
  }
  cout << ans + 1 << '\n';
  return 0;
}
