#include <bits/stdc++.h>
using namespace std;
void dv(vector<long long int> g1) {
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    cout << *i << " ";
  }
}
int invert(int a) {
  if (a == 0) {
    return 1;
  } else if (a == 1) {
    return 0;
  } else {
    return -1;
  }
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i % 1000000007;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return (fact(n) / (fact(r) * fact(n - r))) % 1000000007;
}
long long int nCr1(long long int a, long long int b) {
  if (b > a) {
    return 0;
  } else {
    long long int ans = 1;
    for (long long int i = b + 1; i < a + 1; ++i) {
      ans = ans * i % 1000000007;
    }
    return ans;
  }
}
long long int func(long long int a) {
  if (a % 2 == 0) {
    return -1;
  } else {
    return 1;
  }
}
long long int binsearch(vector<long long int> &a, long long int hi) {
  long long int l = 0, r = a.size() - 1;
  long long int mid, ans = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] > hi) {
      r = mid - 1;
    } else {
      l = mid + 1;
      ans = a[mid];
    }
  }
  return ans;
}
void DFS(vector<vector<long long int>> &adj, long long int v, vector<bool> &vis,
         long long int &x) {
  vis[v] = true;
  for (auto i : adj[v]) {
    if (vis[i] == false) {
      x++;
      DFS(adj, i, vis, x);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  vector<vector<long long int>> adj(n);
  vector<bool> vis(n, false);
  for (long long int i = 0; i < n; ++i) {
    long long int a, b, c, flag = 1;
    cin >> a >> b >> c;
    while (c) {
      if (c % 10 != 7 && c % 10 != 4) {
        flag = 0;
        break;
      }
      c /= 10;
    }
    a--;
    b--;
    if (flag == 0) {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  long long int x, ans = 0;
  for (long long int i = 0; i < n; ++i) {
    if (vis[i] == true) {
    } else {
      x = 1;
      DFS(adj, i, vis, x);
      ans += (n - x) * (n - x - 1) * x;
    }
  }
  cout << ans << endl;
}
