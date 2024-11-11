#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int n, m, id;
long long cur, ans;
long long a[N];
pair<int, int> tme[N];
set<int> st;
map<int, int> mp;
void add(int pos, long long val) {
  while (pos <= id) {
    a[pos] = (a[pos] + val) % MOD;
    pos += pos & -pos;
  }
}
long long query(int pos) {
  long long sum = 0;
  while (pos) {
    sum = (sum + a[pos]) % MOD;
    pos -= pos & -pos;
  }
  return sum;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    st.insert(x);
    st.insert(y);
    tme[i] = pair<int, int>(x, y);
  }
  if (st.find(0) == st.end() || st.find(n) == st.end()) {
    puts("0");
    return 0;
  }
  for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
    id++;
    mp[*it] = id;
  }
  for (int i = 0; i < m; i++)
    tme[i] = pair<int, int>(mp[tme[i].second], mp[tme[i].first]);
  sort(tme, tme + m);
  add(1, 1);
  for (int i = 0; i < m; i++) {
    long long q = (query(tme[i].first) % MOD + MOD -
                   (tme[i].second == 1 ? 0 : query(tme[i].second - 1) % MOD)) %
                  MOD;
    add(tme[i].first, q);
  }
  printf("%d\n", (query(id) % MOD + MOD - query(id - 1) % MOD) % MOD);
  return 0;
}
