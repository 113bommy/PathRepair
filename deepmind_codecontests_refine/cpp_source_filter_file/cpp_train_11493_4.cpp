#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ispalindrome(string ss) {
  long long n = ss.size();
  for (long long i = 0; i < (n + 1) / 2; i++) {
    if (ss[i] != ss[n - i - 1]) return 0;
  }
  return 1;
}
long long mod = 1e14 + 7;
long long ksm(long long a, long long b) {
  long long S = 1;
  while (b) {
    if (b & 1) S = S * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return S;
}
long long digit(long long n) {
  long long res = 0;
  while (n) {
    res++;
    n = n / 10;
  }
  return res;
}
long long fact(long long n) {
  long long ans = 1;
  for (long long i = 1; i < n + 1; i++) ans = (ans * i) % mod;
  return ans;
}
vector<long long> arr[110];
void addedge(long long a, long long b) {
  arr[a].push_back(b);
  arr[b].push_back(a);
}
long long vis[100], cc;
void dfs(long long node) {
  vis[node] = 1;
  cc++;
  for (int child : arr[node]) {
    if (vis[child] == 0) {
      dfs(child);
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    addedge(a, b);
  }
  for (long long i = 0; i < 101; i++) {
    vis[i] = 0;
  }
  long long c = 0;
  for (long long i = 1; i < n + 1; i++) {
    cc = 0;
    if (vis[i] == 0) {
      dfs(i);
      if (cc > 1) c++;
      if (cc > 3) {
        cout << -1;
        return;
      }
    }
  }
  if (c > n / 3) {
    cout << -1;
    return;
  }
  vector<long long> st;
  for (long long i = 1; i < n + 1; i++) {
    if (arr[i].size() == 0) {
      st.push_back(i);
    }
  }
  map<long long, long long> mp;
  mp.clear();
  for (long long i = 1; i < n + 1; i++) {
    if (arr[i].size() == 2 && mp[i] == 0) {
      cout << i << " " << arr[i][0] << " " << arr[i][1] << endl;
      mp[i] = 1;
      mp[arr[i][0]] = 1;
      mp[arr[i][1]] = 1;
    }
    if (arr[i].size() == 1 && mp[i] == 0) {
      cout << i << " " << arr[i][0] << " ";
      mp[i] = 1;
      mp[arr[i][0]] = 1;
      long long pp = 0;
      if (arr[arr[i][0]].size() > 1) {
        for (long long k = 0; k < arr[arr[i][0]].size(); k++) {
          if (mp[arr[arr[i][0]][k]] == 0) {
            cout << arr[arr[i][0]][k] << endl;
            mp[arr[arr[i][0]][k]] = 1;
            pp = 1;
            break;
          }
        }
      }
      if (pp == 0) {
        cout << st[st.size() - 1] << endl;
        mp[st[st.size() - 1]] = 1;
        st.pop_back();
      }
    }
  }
  for (long long i = 0; i < st.size() / 3; i += 3) {
    cout << st[i] << " " << st[i + 1] << " " << st[i + 2] << endl;
  }
}
int main() {
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
