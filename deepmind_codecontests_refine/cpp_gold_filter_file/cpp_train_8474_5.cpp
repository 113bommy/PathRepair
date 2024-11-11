#include <bits/stdc++.h>
using namespace std;
class graph {
 public:
  long long v;
  map<long long, list<long long>> comp;
  map<long long, list<long long>> adj;
  map<long long, list<long long>> rev;
  map<long long, long long> cost;
  map<long long, long long> dist;
  void init(long long n) {
    v = n;
    for (long long i = 1; i <= n; i++) cin >> cost[i];
    long long m;
    cin >> m;
    for (long long i = 1; i <= m; i++) {
      long long a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      rev[b].push_back(a);
    }
  }
  void dfs1(long long node, unordered_map<long long, bool> &visited,
            stack<long long> &s) {
    if (visited[node] == true) return;
    visited[node] = true;
    for (auto child : adj[node]) {
      if (visited[child] == false) {
        dfs1(child, visited, s);
      }
    }
    s.push(node);
  }
  void dfs2(long long node, unordered_map<long long, bool> &visited,
            long long num) {
    if (visited[node] == true) return;
    comp[num].push_back(node);
    visited[node] = true;
    for (auto child : rev[node]) {
      if (visited[child] == false) {
        dfs2(child, visited, num);
      }
    }
  }
  void solve() {
    unordered_map<long long, bool> visited;
    stack<long long> s;
    for (long long i = 1; i <= v; i++) dfs1(i, visited, s);
    visited.clear();
    long long num = 1;
    while (!s.empty()) {
      long long t = s.top();
      s.pop();
      if (visited[t] == true) continue;
      dfs2(t, visited, num);
      num++;
    }
    long long minCost = 0;
    long long answer = 1;
    for (auto node : comp) {
      long long temp = INT_MAX;
      for (auto elem : node.second) temp = min(temp, cost[elem]);
      long long cnt = 0;
      for (auto elem : node.second) cnt = cost[elem] == temp ? (cnt + 1) : cnt;
      answer = (answer * cnt) % 1000000007;
      minCost += temp;
    }
    cout << minCost << " " << answer << endl;
  }
};
bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}
int32_t main() {
  map<long long, long long> cnt;
  long long a;
  cin >> a;
  string s;
  cin >> s;
  vector<long long> pref;
  long long n = s.length();
  for (auto node : s) pref.push_back(node - '0');
  for (long long i = 1; i < s.length(); i++) pref[i] += pref[i - 1];
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      long long sum = pref[j];
      if (i != 0) sum -= pref[i - 1];
      cnt[sum]++;
    }
  }
  long long answer = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      long long sum = pref[j];
      if (i != 0) sum -= pref[i - 1];
      if (sum != 0 && a % sum == 0) {
        long long tmp = a / sum;
        answer += cnt[tmp];
      } else if (sum == 0 && a == 0) {
        answer += (n * (n + 1)) / 2;
      }
    }
  }
  cout << answer << endl;
}
