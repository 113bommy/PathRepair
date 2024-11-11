#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, t, ans, res, sum, mn = 1e9, cnt, mx, k, z, mnn = 1e9, mxx,
                                  b = 1, i;
string s1, s3, s2, s;
set<long long> st;
pair<long long, long long> p[1000001];
vector<int> v, v1, v3, v4, v2;
map<char, long long> mp, mpp;
char c, d, e, a;
bool tr = false, fl = false;
int used[10001];
int main() {
  cin >> s >> m;
  set<char> st;
  if (s.size() < m)
    cout << "Impossible";
  else {
    for (int i = 0; i < s.size(); i++) st.insert(s[i]);
    if (st.size() >= m)
      cout << 0;
    else
      cout << m - st.size();
  }
}
