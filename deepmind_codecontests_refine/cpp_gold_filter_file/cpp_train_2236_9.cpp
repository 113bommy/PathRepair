#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000110;
int n, k;
long long s[Nmax], m[Nmax];
long long answer[Nmax];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> m[i];
  }
  set<pair<long long, int> > st;
  for (int i = 1; i <= n; i++) {
    if (st.size() < k) {
      st.insert(make_pair(s[i] + m[i], i));
      continue;
    }
    pair<long long, int> cur = *st.begin();
    st.erase(st.begin());
    answer[cur.second] = cur.first - 1;
    long long firstTime = s[i];
    if (cur.first > firstTime) firstTime = cur.first;
    st.insert(make_pair(firstTime + m[i], i));
  }
  while (st.size() > 0) {
    pair<long long, int> cur = *st.begin();
    st.erase(st.begin());
    answer[cur.second] = cur.first - 1;
  }
  for (int i = 1; i <= n; i++) cout << answer[i] + 1 << endl;
  return 0;
}
