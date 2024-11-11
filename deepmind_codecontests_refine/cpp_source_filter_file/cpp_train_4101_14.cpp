#include <bits/stdc++.h>
using namespace std;
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
unsigned int n, k, x, IPs[100100];
inline unsigned int toInt(const string& s) {
  int val, prv = -1;
  vector<int> vec;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      val = stoi(s.substr(prv + 1, i - prv));
      vec.push_back(val);
      prv = i;
    }
  }
  val = stoi(s.substr(prv + 1));
  vec.push_back(val);
  unsigned int res = 0;
  for (int x : vec) res = (res << 8) + x;
  return res;
}
inline string toIP(unsigned int num) {
  string res;
  vector<int> vec;
  for (int i = 0; i < 4; ++i) {
    vec.push_back(num & 255);
    num >>= 8;
  }
  for (int i = 3; i >= 0; --i) {
    res += to_string(vec[i]) + ".";
  }
  res.pop_back();
  return res;
}
inline bool solve(unsigned int mask) {
  set<unsigned int> st;
  for (int i = 0; i < n; ++i) {
    st.insert(IPs[i] & mask);
  }
  return (st.size() == k);
}
int main() {
  boostIO();
  string s;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    IPs[i] = toInt(s);
  }
  unsigned int mask = 0;
  for (int i = 31; i >= 0; --i) {
    mask |= (1LL << i);
    if (solve(mask)) {
      return cout << toIP(mask) << endl, 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
