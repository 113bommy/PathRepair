#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 50;
int l[maxn], r[maxn];
vector<int> adj[maxn];
bool mark[maxn];
int counter = 0;
int multi = -1;
vector<int> x;
bool f(int i, int j) {
  if (l[i] <= l[j] && r[i] > l[j]) return true;
  if (l[j] <= l[i] && r[j] > l[i]) return true;
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (f(i, j)) {
        adj[i].push_back(j);
        adj[j].push_back(i);
        if (!mark[i]) {
          mark[i] = true;
          x.push_back(i);
        }
        if (!mark[j]) {
          mark[j] = true;
          x.push_back(j);
        }
        if (adj[i].size() > 1 && multi != i) {
          if (multi != -1) {
            cout << 0;
            return 0;
          }
          multi = i;
        }
        if (adj[j].size() > 1 && multi != j) {
          if (multi != -1) {
            cout << 0;
            return 0;
          }
          multi = j;
        }
      }
  if (x.size() == 0) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    return 0;
  }
  if (multi != -1) {
    cout << 1 << endl << multi + 1;
    return 0;
  }
  if (x.size() > 2) {
    cout << 0;
    return 0;
  }
  sort(x.begin(), x.end());
  cout << 2 << endl << x[0] + 1 << " " << x[1] + 1;
  return 0;
}
