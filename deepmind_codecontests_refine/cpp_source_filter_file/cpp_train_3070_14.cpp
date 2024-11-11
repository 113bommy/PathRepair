#include <bits/stdc++.h>
using namespace std;
long long int ceil1(long long int n, long long int m) {
  if (n % m == 0) {
    return n / m;
  }
  return n / m + 1;
}
vector<long long int> factor(long long int n) {
  vector<long long int> ans;
  if (n > 0) ans.push_back(1);
  if (n == 2) ans.push_back(2);
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (n / i != i) ans.push_back(n / i);
    }
  }
  if (n > 2) ans.push_back(n);
  return ans;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
void dfs(vector<vector<long long int>> &v, long long int k,
         vector<long long int> &par, vector<long long int> &dis,
         long long int p) {
  par[k] = p;
  dis[k] = dis[p] + 1;
  for (long long int i = 0; i < v[k].size(); i++) {
    if (v[k][i] != p) {
      dfs(v, v[k][i], par, dis, k);
    }
  }
}
bool sortbysec(const pair<string, int> &a, const pair<string, int> &b) {
  return (a.second < b.second);
}
long long int ston(string s) {
  stringstream geek(s);
  long long int x = 0;
  geek >> x;
  return x;
}
long long int pow2(long long int n, long long int k) {
  long long int ans = 1;
  while (k > 0) {
    if (k % 2 == 1) ans = ans * n;
    n = n * n;
    k /= 2;
  }
  return ans;
}
bool prime(int n) {
  int i, j;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool bserch(vector<string> a, string s) {
  long long int l = 0, r = a.size() - 1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] == s) return true;
    if (a[mid] < s) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return false;
}
bool sortcol(const vector<int> &v1, const vector<int> &v2) {
  return v1[0] < v2[0];
}
long long int degit(long long int n) {
  long long int t = 0;
  while (n > 0) {
    t++;
    n /= 10;
  }
  return t;
}
void solve() {
  string s, t;
  string p = " ";
  cin >> s >> t;
  long long int dif = 0;
  for (long long int i = 0; i < s.size(); i++)
    if (s[i] != t[i]) dif++;
  if (dif % 2 == 1)
    cout << "Impossible";
  else {
    long long int fl = 0;
    for (long long int i = 0; i < s.size(); i++) {
      if (s[i] != t[i]) {
        if (fl == 0)
          p += s[i], fl = 1;
        else
          p += t[i], fl = 0;
      } else
        p += s[i];
    }
    cout << p;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int q;
  q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
