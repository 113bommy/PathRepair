#include <bits/stdc++.h>
using namespace std;
int n, d, k;
int done;
void ex() {
  cout << "NO" << '\n';
  exit(0);
}
vector<int> adj[400005];
void add(int par, int left) {
  if (done >= n) return;
  if (left <= 0) return;
  while (done < n) {
    if (adj[par].size() < k) {
      done += 1;
      adj[par].push_back(done);
      adj[done].push_back(par);
      add(done, left - 1);
    } else
      break;
  }
}
int main() {
  cin >> n >> d >> k;
  if (d > n - 1) {
    ex();
  }
  for (int i = 1; i < d + 1; i++) {
    adj[i].push_back(i + 1);
    adj[i + 1].push_back(i);
  }
  for (int i = 1; i < n + 1; i++) {
    if (adj[i].size() > k) {
      ex();
    }
  }
  done = d + 1;
  for (int i = 2; i < d + 1; i++) {
    add(i, min(i - 1, d + 1 - i));
  }
  if (done < n) ex();
  cout << "YES" << '\n';
  for (int i = 1; i < n + 1; i++) {
    for (auto x : adj[i]) {
      if (x > i) cout << i << " " << x << '\n';
    }
  }
  exit(0);
}
