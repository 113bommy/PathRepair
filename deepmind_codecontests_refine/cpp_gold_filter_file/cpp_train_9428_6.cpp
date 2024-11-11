#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int mod = 998244353;
vector<long long> v[N];
long long colour[N], vis[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  for (int i = 1; i <= 2 * n; i += 2) {
    v[i].push_back(i + 1);
    v[i + 1].push_back(i);
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (!vis[i]) {
      queue<long long> q;
      q.push(i);
      colour[q.front()] = 1;
      vis[i] = 1;
      while (!q.empty()) {
        long long x = q.front();
        q.pop();
        for (auto it : v[x]) {
          if (!vis[it] && !colour[it]) {
            colour[it] = 3 - colour[x];
            q.push(it);
            vis[it] = 1;
          } else if (colour[it] == colour[x] && !colour[it])
            return cout << -1, 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << colour[a[i]] << " " << colour[b[i]] << "\n";
  return 0;
}
