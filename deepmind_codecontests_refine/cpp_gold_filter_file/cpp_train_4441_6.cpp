#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 1) return (power(a, b - 1) * a) % 1000000007;
  long long int q = power(a, b / 2);
  return (q * q) % 1000000007;
}
vector<long long int> adj[1000000];
long long int apples[1000000];
bool vis[1000000];
long long int steps[1000000];
int main() {
  std::ios::sync_with_stdio(false);
  long long int n;
  cin >> n;
  for (int i = 0; i < 1000000; i++) steps[i] = -1;
  long long int p[n + 10];
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    adj[p[i]].push_back(i);
  }
  queue<long long int> q;
  q.push(1);
  steps[1] = 1;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    apples[steps[a]]++;
    for (int i = 0; i < adj[a].size(); i++) {
      if (!vis[adj[a][i]]) {
        vis[adj[a][i]] = 1;
        steps[adj[a][i]] = steps[a] + 1;
        q.push(adj[a][i]);
      }
    }
  }
  vector<long long int> vec;
  for (int i = 2; i <= n; i++)
    if (apples[i] % 2 != 0) vec.push_back(1);
  cout << vec.size() + 1 << "\n";
  return 0;
}
