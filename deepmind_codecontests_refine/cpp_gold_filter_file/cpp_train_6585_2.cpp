#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
void debug(vector<long long>& v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << endl;
}
void countSort(long long k, vector<long long>& SA, vector<long long>& eqC) {
  long long n = SA.size();
  long long maxi = max(300, n);
  vector<long long> count(maxi, 0);
  for (long long i = 0; i < n; i++) count[i + k < n ? eqC[i + k] : 0]++;
  vector<long long> pos(maxi, 0);
  pos[0] = 0;
  for (long long i = 1; i < maxi; i++) pos[i] = pos[i - 1] + count[i - 1];
  vector<long long> tempSA(n, 0);
  for (long long i = 0; i < n; i++)
    tempSA[pos[SA[i] + k < n ? eqC[SA[i] + k] : 0]++] = SA[i];
  for (long long i = 0; i < n; i++) SA[i] = tempSA[i];
}
vector<long long> buildSA(string& t) {
  t += '$';
  long long n = t.length();
  vector<long long> SA(n, 0), eqC(n, 0);
  for (long long i = 0; i < n; i++) SA[i] = i;
  for (long long i = 0; i < n; i++) eqC[i] = t[i];
  for (long long k = 1; k < n; k <<= 1) {
    countSort(k, SA, eqC);
    countSort(0, SA, eqC);
    vector<long long> tempEqC(n, 0);
    long long r = tempEqC[SA[0]] = 0;
    for (long long i = 1; i < n; i++) {
      if (eqC[SA[i]] == eqC[SA[i - 1]] && eqC[SA[i] + k] == eqC[SA[i - 1] + k])
        tempEqC[SA[i]] = r;
      else
        tempEqC[SA[i]] = ++r;
    }
    for (long long i = 0; i < n; i++) eqC[i] = tempEqC[i];
  }
  return SA;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> t(n, 0);
  for (long long i = 0; i < t.size(); i++) cin >> t[i];
  ;
  map<long long, long long> c;
  vector<map<long long, long long> > v(m + 1, c);
  map<long long, long long> at;
  for (long long i = 1; i <= n; i++) {
    v[t[i - 1]][i]++;
    at[i] = t[i - 1];
  }
  vector<long long> id(m + 1, 0);
  for (long long i = 0; i <= m; i++) id[i] = i;
  long long ans = 0;
  for (long long i = n; i > 1; i--) {
    if (at[i] == at[i - 1])
      ;
    else
      ans++;
  }
  cout << ans << endl;
  while (m-- > 1) {
    long long a, b;
    cin >> a >> b;
    if (v[id[a]].size() > v[id[b]].size()) {
      for (auto i = v[id[b]].begin(); i != v[id[b]].end(); i++) {
        long long ele = i->first;
        if (v[id[a]].find(ele - 1) != v[id[a]].end()) ans--;
        if (v[id[a]].find(ele + 1) != v[id[a]].end()) ans--;
      }
      for (auto i = v[id[b]].begin(); i != v[id[b]].end(); i++) {
        long long ele = i->first;
        v[id[a]][ele]++;
      }
      id[b] = id[a];
    } else {
      for (auto i = v[id[a]].begin(); i != v[id[a]].end(); i++) {
        long long ele = i->first;
        if (v[id[b]].find(ele - 1) != v[id[b]].end()) ans--;
        if (v[id[b]].find(ele + 1) != v[id[b]].end()) ans--;
      }
      for (auto i = v[id[a]].begin(); i != v[id[a]].end(); i++) {
        long long ele = i->first;
        v[id[b]][ele]++;
      }
      id[a] = id[b];
    }
    cout << ans << endl;
  }
  return 0;
}
