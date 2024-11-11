#include <bits/stdc++.h>
using namespace std;
void enter(vector<long long int> &ar) {
  long long int n = ar.size();
  for (long long int i = 0; i < n; i++) {
    cin >> ar[i];
  }
}
void show(vector<long long int> &a) {
  long long int n = a.size();
  for (long long int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
void SieveOfEratosthenes(int n, vector<long long int> &pri) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      pri.push_back(p);
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
void topo(vector<vector<long long int>> &dir, vector<long long int> &got,
          vector<bool> &visited, long long int parent) {
  visited[parent] = true;
  for (long long int a : dir[parent]) {
    if (!visited[a]) {
      topo(dir, got, visited, a);
    }
  }
  got.push_back(parent);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<vector<long long int>> dir(n);
    vector<pair<long long int, long long int>> undir;
    while (m--) {
      long long int t, x, y;
      cin >> t >> x >> y;
      x--;
      y--;
      if (t) {
        dir[x].push_back(y);
      }
      undir.push_back(make_pair(x, y));
    }
    vector<long long int> got;
    vector<bool> visited(n, false);
    for (long long int i = 0; i < n; i++) {
      if (!visited[i]) {
        topo(dir, got, visited, 0);
      }
    }
    long long int i = 0;
    reverse(got.begin(), got.end());
    vector<long long int> index(n);
    for (long long int j = 0; j < n; j++) {
      index[got[j]] = j;
    }
    bool pos = true;
    for (long long int j = 0; j < n; j++) {
      for (long long int a : dir[j]) {
        if (index[j] > index[a]) {
          pos = false;
        }
      }
    }
    if (pos) {
      cout << "YES\n";
      for (pair<long long int, long long int> a : undir) {
        long long int f = a.first, s = a.second;
        if (index[s] < index[f]) {
          cout << f + 1 << " " << s + 1 << "\n";
        } else {
          cout << s + 1 << " " << f + 1 << "\n";
        }
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
