#include <bits/stdc++.h>
using namespace std;
inline long long get_num(char ch) {
  if (ch == '-')
    return 0;
  else if (ch >= 'a' && ch <= 'z') {
    return 1 + (ch - 'a');
  } else if (ch >= 'A' && ch <= 'Z') {
    return 27 + (ch - 'A');
  } else if (ch >= '0' && ch <= '9') {
    return 53 + (ch - '0');
  }
}
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
inline int GA(long long n, vector<long long>& vec) {
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    vec.push_back(x);
  }
}
inline int GAEG(long long m, vector<long long> vec[]) {
  for (long long i = 0; i < m; ++i) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
}
set<long long> st;
set<long long>::iterator it;
map<long long, bool> ri;
map<long long, bool> le;
long long ans[100001];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    it = st.upper_bound(x);
    if (it != st.end() && !le[*it]) {
      le[*it] = true;
      ans[i] = *it;
    } else {
      if (!st.empty()) it--;
      if (le[*(it)]) continue;
      ri[*(it)] = true;
      ans[i] = *it;
    }
    st.insert(x);
  }
  for (long long i = 1; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
