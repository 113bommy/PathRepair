#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050, maxm = 100050;
int n, m;
long long gt, rt, T, len[maxn], dep[maxn], stop[maxn + maxm], arrive[maxn];
set<pair<long long, int> > st;
void updateStop(long long ll, long long rr, int sp) {
  pair<long long, int> low = make_pair(ll, -1);
  set<pair<long long, int> >::iterator dL = st.lower_bound(low), dR = dL;
  while (dR != st.end() && dR->first <= rr) {
    stop[dR->second] = sp;
    dR++;
  }
  st.erase(dL, dR);
}
int main() {
  cin >> n >> gt >> rt;
  T = gt + rt;
  for (int i = 1; i <= n + 1; i++) {
    cin >> len[i];
    len[i] += len[i - 1];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> dep[i];
    st.insert(make_pair(dep[i] % T, n + 1 + i));
  }
  for (int i = 1; i <= n + m + 1; i++) stop[i] = n + 1;
  for (int i = 1, sum = 0; i <= n; i++) {
    long long A = len[i] % T, B = gt;
    long long ll = (B - A + T) % T, rr = T - A;
    updateStop(ll, rr < ll ? T - 1 : rr, i);
    if (rr < ll) updateStop(0, rr, i);
    long long ins = (T - len[i] % T) % T;
    st.insert(make_pair(ins, i));
  }
  arrive[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    long long firstStop = len[stop[i]] - len[i];
    long long wait = stop[i] == n + 1 ? 0 : (T - firstStop % T);
    arrive[i] = firstStop + wait + arrive[stop[i]];
  }
  for (int i = 1; i <= m; i++) {
    long long firstStop = dep[i] + len[stop[n + 1 + i]];
    long long wait = stop[n + 1 + i] == n + 1 ? 0 : (T - firstStop % T);
    long long res = firstStop + wait + arrive[stop[n + 1 + i]];
    cout << res << endl;
  }
  return 0;
}
