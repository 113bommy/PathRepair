#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};
vector<int> kmp(string& s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> find_occurences(string& text, string& pattern) {
  string cur = pattern + '#' + text;
  int sz1 = text.size(), sz2 = pattern.size();
  vector<int> v;
  vector<int> lps = kmp(cur);
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (lps[i] == sz2) v.push_back(i - 2 * sz2);
  }
  return v;
}
long long topo_sort(vector<vector<long long>>& g) {
  int n = int(g.size());
  vector<int> ind(n, 0);
  vector<bool> vis(n, false);
  for (auto v : g) {
    for (auto x : v) {
      ind[x]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (ind[i] == 0) q.push({i});
  }
  bool check = true;
  vector<long long> dis(n);
  long long ans = 0;
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    n--;
    if (vis[x]) {
      check = false;
      break;
    }
    vis[x] = true;
    for (auto a : g[x]) {
      ind[a]--;
      dis[a] = max(dis[a], dis[x] + 1);
      if (ind[a] == 0) q.push(a);
    }
  }
  if (n != 0) check = false;
  if (check == false) return -1;
  return (*max_element((dis).begin(), (dis).end()));
}
string solve() {
  int n;
  cin >> n;
  string x;
  cin >> x;
  long long pos = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (x[i] > x[i + 1]) {
      pos = i;
      break;
    }
  }
  string ans = "";
  for (long long i = 0; i < n; i++) {
    if (i == pos) continue;
    ans += x[i];
  }
  if (x < ans) return x;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << solve() << '\n';
}
