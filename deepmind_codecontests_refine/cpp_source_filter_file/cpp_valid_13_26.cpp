#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
void debugi(vector<int>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugd(vector<long double>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugl(vector<ll>& vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
void debugmap(map<int, int>& mp) {
  for (auto x : mp) {
    cout << x.first << " " << x.second << " , ";
  }
  cout << endl;
}
void debugset(set<int>& st) {
  for (auto x : st) {
    cout << x << " ";
  }
  cout << endl;
}
void debugparri(vector<pair<int, int>>& arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    cout << "[" << arr[i].first << " : " << arr[i].second << "]"
         << " ";
  }
  cout << endl;
}
void debugpi(pair<int, int>& pi) {
  cout << pi.first << " " << pi.second << endl;
}
void debugq(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
bool check(int n, int i, int j) {
  if ((0 <= i & i < n) && (0 <= j & j < n)) {
    return true;
  }
  return false;
}
ll MOD = 1e9 + 7;
ll powab(ll a, ll b, ll mod) {
  if (b == 0) {
    return 1;
  }
  ll z = powab(a, b / 2, mod);
  ll res = (z * z * 1LL) % mod;
  if (b & 1) {
    res = (res * 1LL * a) % mod;
  }
  return res;
}
ll modinv(ll a, ll mod) {
  ll ans = powab(a, mod - 2, mod);
  return ans;
}
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void upd(int k, int x, vector<ll>& tree, int n) {
  if (k == 0) {
    return;
  }
  while (k <= n) {
    tree[k] += x;
    k += (k & -k);
  }
}
ll sum(int k, vector<ll>& tree, int n) {
  ll s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= (k & -k);
  }
  return s;
}
void solve(int tt, int t) {
  int n, m, k, rn;
  cin >> n >> m >> k;
  rn = n;
  int lim = 5050;
  vector<int> dp(lim), lst(lim, -1);
  vector<int> arr;
  if (m == 1) {
    if (k != 0) {
      cout << "NO" << endl;
      return;
    }
    if (n % 2 != 0) {
      cout << "NO " << endl;
      return;
    }
    vector<vector<char>> grid(n, vector<char>(m));
    int ct = 1;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && ct) {
        grid[i][0] = 'a';
        grid[i + 1][0] = 'a';
        ct ^= 1;
      }
      if (i % 2 == 0 && !ct) {
        grid[i][0] = 'b';
        grid[i + 1][0] = 'b';
        ct ^= 1;
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
    return;
  }
  vector<vector<int>> grid(n, vector<int>(m, -1));
  dp[0] = 1;
  if (n % 2 != 0) {
    if (k < m / 2) {
      cout << "NO" << endl;
      return;
    }
    k -= m / 2;
    int ct = 1;
    for (int i = 0; i < m; i += 2) {
      if (ct) {
        grid[n - 1][i] = 1;
        grid[n - 1][i + 1] = 1;
        ct ^= 1;
      } else {
        grid[n - 1][i] = 0;
        grid[n - 1][i + 1] = 0;
        ct ^= 1;
      }
    }
    n -= 1;
  }
  if (n % 2 == 0) {
    for (int i = 2; i <= n; i += 2) {
      arr.push_back(i);
    }
  } else {
    for (int i = 1; i <= n; i += 2) {
      arr.push_back(i);
    }
  }
  reverse(arr.begin(), arr.end());
  queue<pair<int, int>> q;
  q.push({0, 0});
  vector<int> vis(lim);
  vis[0] = 1;
  while (!q.empty()) {
    int cur = q.front().first, dis = q.front().second;
    q.pop();
    for (auto x : arr) {
      if (x + cur < lim) {
        if (vis[x + cur] == 0) {
          vis[x + cur] = 1;
          q.push({x + cur, dis + 1});
          lst[x + cur] = cur;
          dp[x + cur] = dis + 1;
        }
      }
    }
  }
  n = rn;
  if (vis[k] == 1 && dp[k] <= m / 2) {
    vector<int> nums;
    int cur = k;
    while (cur != 0) {
      int prev = lst[cur];
      nums.push_back(cur - prev);
      cur = prev;
    }
    int z = nums.size(), idx = 0;
    vector<int> curcol(m);
    int cl = 2;
    for (int i = 0; i < m; i++) {
      if (i % 2 == 0) {
        curcol[i] = 2;
      } else
        curcol[i] = 3;
    }
    for (int i = 0; i < m; i += 2) {
      int use = 0;
      if (idx < z) {
        use = nums[idx];
        idx += 1;
      }
      int col = i, col1 = i + 1;
      int color = 0, st = n - 1, curcol = 2;
      if (grid[n - 1][i] != -1) {
        color = grid[n - 1][0] ^ 1;
        st = n - 2;
      }
      if (i != 0 && st >= 0) {
        if (grid[st][i - 1] == 0)
          color = 1;
        else
          color = 0;
      }
      while (use > 0 && st >= 0) {
        grid[st][col] = color;
        grid[st][col1] = color;
        use -= 1;
        color ^= 1;
        st -= 1;
      }
    }
    for (int i = 0; i < m; i++) {
      int now = curcol[i];
      for (int j = 0; j < n; j += 2) {
        if (grid[j][i] != -1) break;
        grid[j][i] = now;
        grid[j + 1][i] = now;
        if (now == 2)
          now = 3;
        else
          now = 2;
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << char(97 + grid[i][j]);
      }
      cout << endl;
    }
    return;
  }
  cout << "NO" << endl;
  return;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve(tt, t);
  }
  return 0;
}
