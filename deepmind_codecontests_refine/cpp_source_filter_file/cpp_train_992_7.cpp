#include <bits/stdc++.h>
using namespace std;
int ar[200001];
bool visited[200001];
bool visiting[200001];
int root = 0;
int c = 0;
int n;
void func(int u) {
  if (visited[u]) return;
  visited[u] = true;
  visiting[u] = true;
  if (visiting[ar[u]]) {
    if (root == 0 && ar[u] == u) {
      root = u;
    } else if (ar[u] != root) {
      c++;
      ar[u] = root;
    }
  } else
    func(ar[u]);
  visiting[u] = false;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    visiting[i] = false;
    visited[i] = false;
    cin >> ar[i];
  }
  for (int i = 1; i <= n; ++i) func(i);
  int pr = 0;
  for (int i = 1; i < n; ++i) {
    if (ar[i] != 0) continue;
    if (root != 0) {
      if (ar[i] == 0) ar[i] = root;
    } else {
      if (pr == 0) {
        pr = i;
        ar[i] = pr;
      } else
        ar[i] = pr;
    }
  }
  cout << c << "\n";
  for (int i = 1; i <= n; ++i) cout << ar[i] << " ";
  return 0;
}
