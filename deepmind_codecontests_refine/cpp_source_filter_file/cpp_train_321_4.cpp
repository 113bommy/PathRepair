#include <bits/stdc++.h>
using namespace std;
char _;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long fpow(long long b, long long exp, long long mod) {
  if (exp == 0) return 1;
  long long t = fpow(b, exp / 2, mod);
  if (exp & 1) return t * t % mod * b % mod;
  return t * t % mod;
}
int num_cases, num_nodes, num_A, num_B;
bool marked[1005], vis[1005];
vector<int> connections[1005];
unordered_set<int> A, B;
int main() {
  cin >> num_cases;
  for (int t = 0; t < num_cases; t++) {
    cin >> num_nodes;
    for (int i = 1; i <= num_nodes; i++) connections[i].clear();
    for (int i = 0; i < num_nodes - 1; i++) {
      int a, b;
      cin >> a >> b;
      connections[a].push_back(b);
      connections[b].push_back(a);
    }
    cin >> num_A;
    A.clear(), B.clear();
    memset(marked, false, sizeof marked);
    for (int i = 1; i <= num_A; i++) {
      int n;
      cin >> n;
      A.insert(n);
      marked[n] = true;
    }
    cin >> num_B;
    for (int i = 1; i <= num_B; i++) {
      int n;
      cin >> n;
      B.insert(n);
    }
    int first = *B.begin();
    cout << "B " << first << "\n";
    int ans;
    cin >> ans;
    if (A.count(ans)) {
      cout << "C " << ans << "\n";
      continue;
    }
    memset(vis, false, sizeof vis);
    queue<int> q;
    q.push(ans);
    vis[ans] = true;
    bool done = false;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      if (marked[node]) {
        cout << "A " << node << "\n";
        cin >> ans;
        if (B.count(ans)) {
          cout << "C " << node << "\n";
          done = true;
          break;
        }
        break;
      }
      for (int check : connections[node]) {
        if (!vis[check]) {
          vis[check] = true;
          q.push(check);
        }
      }
    }
    if (!done)
      cout << "-1"
           << "\n";
  }
}
