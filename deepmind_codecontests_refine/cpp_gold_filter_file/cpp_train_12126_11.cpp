#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << "," << a.second << ")";
}
template <class A>
ostream &operator<<(ostream &out, const vector<A> &a) {
  for (const A &it : a) out << it << " ";
  return out;
}
template <class A, class B>
istream &operator>>(istream &in, pair<A, B> &a) {
  return in >> a.first >> a.second;
}
template <class A>
istream &operator>>(istream &in, vector<A> &a) {
  for (A &i : a) in >> i;
  return in;
}
ifstream cinn("input.txt");
ofstream coutt("output.txt");
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<string> v(n);
  cin >> v;
  vector<long long> adj[26];
  long long indeg[26] = {0};
  for (long long i = 0; i < n; i++) {
    if (i) {
      bool ok = 1;
      for (long long j = 0; j < min(v[i].size(), v[i - 1].size()); j++)
        ok &= (v[i][j] == v[i - 1][j]);
      if (ok && v[i - 1].size() > v[i].size()) {
        cout << "Impossible";
        return 0;
      }
    }
    for (long long j = i + 1; j < n; j++) {
      for (long long k = 0; k < min(v[i].size(), v[j].size()); k++) {
        if (v[i][k] != v[j][k]) {
          adj[v[i][k] - 'a'].push_back(v[j][k] - 'a');
          indeg[v[j][k] - 'a']++;
          break;
        }
      }
    }
  }
  queue<long long> q;
  for (long long i = 0; i < 26; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  string ans = "";
  while (!q.empty()) {
    long long cur = q.front();
    q.pop();
    ans += (cur + 'a');
    for (long long ch : adj[cur]) {
      indeg[ch]--;
      if (indeg[ch] == 0) {
        q.push(ch);
      }
    }
  }
  if (ans.size() == 26)
    cout << ans;
  else
    cout << "Impossible";
}
