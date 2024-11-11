#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long N = 100005;
const long long M = 1000000007;
const long long M2 = 998244353;
const long long INF = 1e12;
long long pow1(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % M;
    }
    a = (a * a) % M;
    b >>= 1;
  }
  return res % M;
}
vector<vector<long long> > a;
vector<vector<pair<long long, long long> > > ans2;
vector<pair<long long, long long> > ans;
void solve(long long i, long long j) {
  long long sum = 0;
  sum += (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]);
  if (sum == 0) return;
  if (sum == 4) {
    a[i][j] ^= 1;
    a[i][j + 1] ^= 1;
    a[i + 1][j] ^= 1;
    ans.push_back({i + 1, j + 1});
    ans.push_back({i + 1, j + 2});
    ans.push_back({i + 2, j + 1});
    ans2.push_back(ans);
    ans.clear();
    solve(i, j);
  } else if (sum == 3) {
    if (a[i][j] == 1) {
      a[i][j] ^= 1;
      ans.push_back({i + 1, j + 1});
    }
    if (a[i][j + 1] == 1) {
      a[i][j + 1] ^= 1;
      ans.push_back({i + 1, j + 2});
    }
    if (a[i + 1][j] == 1) {
      a[i + 1][j] ^= 1;
      ans.push_back({i + 2, j + 1});
    }
    if (a[i + 1][j + 1] == 1) {
      a[i + 1][j + 1] ^= 1;
      ans.push_back({i + 2, j + 2});
    }
    ans2.push_back(ans);
    ans.clear();
    solve(i, j);
  } else if (sum == 2) {
    long long cnt = 0;
    if (a[i][j] == 1 && cnt == 0) {
      a[i][j] = 0;
      cnt = 1;
      ans.push_back({i + 1, j + 1});
    } else if (a[i][j] == 0) {
      a[i][j] = 1;
      ans.push_back({i + 1, j + 1});
    }
    if (a[i][j + 1] == 1 && cnt == 0) {
      a[i][j + 1] = 0;
      cnt = 1;
      ans.push_back({i + 1, j + 2});
    } else if (a[i][j + 1] == 0) {
      a[i][j + 1] = 1;
      ans.push_back({i + 1, j + 2});
    }
    if (a[i + 1][j] == 1 && cnt == 0) {
      a[i + 1][j] = 0;
      cnt = 1;
      ans.push_back({i + 2, j + 1});
    } else if (a[i + 1][j] == 0) {
      a[i + 1][j] = 1;
      ans.push_back({i + 2, j + 1});
    }
    if (a[i + 1][j + 1] == 1 && cnt == 0) {
      a[i + 1][j + 1] = 0;
      cnt = 1;
      ans.push_back({i + 2, j + 2});
    } else if (a[i + 1][j + 1] == 0) {
      a[i + 1][j + 1] = 1;
      ans.push_back({i + 2, j + 2});
    }
    ans2.push_back(ans);
    ans.clear();
    solve(i, j);
  } else {
    if (a[i][j] == 1) {
      ans.push_back({i + 1, j + 1});
      ans.push_back({i + 2, j + 2});
      ans.push_back({i + 2, j + 1});
      a[i][j] ^= 1;
      a[i + 1][j + 1] ^= 1;
      a[i + 1][j] ^= 1;
    } else if (a[i][j + 1] == 1) {
      ans.push_back({i + 1, j + 2});
      ans.push_back({i + 2, j + 2});
      ans.push_back({i + 2, j + 1});
      a[i][j + 1] ^= 1;
      a[i + 1][j + 1] ^= 1;
      a[i + 1][j] ^= 1;
    } else if (a[i + 1][j] == 1) {
      ans.push_back({i + 1, j + 2});
      ans.push_back({i + 2, j + 1});
      ans.push_back({i + 1, j + 1});
      a[i][j + 1] ^= 1;
      a[i + 1][j] ^= 1;
      a[i][j] ^= 1;
    } else if (a[i + 1][j + 1] == 1) {
      ans.push_back({i + 1, j + 2});
      ans.push_back({i + 2, j + 2});
      ans.push_back({i + 1, j + 1});
      a[i][j + 1] ^= 1;
      a[i + 1][j + 1] ^= 1;
      a[i][j] ^= 1;
    }
    ans2.push_back(ans);
    ans.clear();
    solve(i, j);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    a = vector<vector<long long> >(n, vector<long long>(m));
    for (long long i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (long long j = 0; j < m; j++) a[i][j] = (s[j] - '0');
    }
    for (long long i = 0; i < n - 1; i++) {
      for (long long j = 0; j < m - 1; j++) {
        if (a[i][j] == 1 && a[i][j + 1] == 1) {
          a[i][j] = 0;
          a[i][j + 1] = 0;
          a[i + 1][j] ^= 1;
          ans.push_back({i + 1, j + 1});
          ans.push_back({i + 1, j + 2});
          ans.push_back({i + 2, j + 1});
        } else if (a[i][j] == 0 && a[i][j + 1] == 1) {
          a[i][j + 1] = 0;
          a[i + 1][j + 1] ^= 1;
          a[i + 1][j] ^= 1;
          ans.push_back({i + 1, j + 2});
          ans.push_back({i + 2, j + 2});
          ans.push_back({i + 2, j + 1});
        } else if (a[i][j] == 1 && a[i][j + 1] == 0) {
          a[i][j] = 0;
          a[i + 1][j + 1] ^= 1;
          a[i + 1][j] ^= 1;
          ans.push_back({i + 1, j + 1});
          ans.push_back({i + 2, j + 2});
          ans.push_back({i + 2, j + 1});
        }
        if (ans.size() != 0) {
          ans2.push_back(ans);
          ans.clear();
        }
      }
    }
    for (long long j = 0; j < m - 1; j++) {
      for (long long i = n - 2; i < n - 1; i++) {
        if (a[i][j] == 1 && a[i + 1][j] == 1) {
          a[i][j] = 0;
          a[i + 1][j] = 0;
          a[i][j + 1] ^= 1;
          ans.push_back({i + 1, j + 1});
          ans.push_back({i + 1, j + 2});
          ans.push_back({i + 2, j + 1});
        } else if (a[i][j] == 0 && a[i + 1][j] == 1) {
          a[i + 1][j] = 0;
          a[i][j + 1] ^= 1;
          a[i + 1][j + 1] ^= 1;
          ans.push_back({i + 2, j + 1});
          ans.push_back({i + 1, j + 2});
          ans.push_back({i + 2, j + 2});
        } else if (a[i][j] == 1 && a[i + 1][j] == 0) {
          a[i][j] = 0;
          a[i][j + 1] ^= 1;
          a[i + 1][j + 1] ^= 1;
          ans.push_back({i + 1, j + 1});
          ans.push_back({i + 1, j + 2});
          ans.push_back({i + 2, j + 2});
        }
        if (ans.size() != 0) {
          ans2.push_back(ans);
          ans.clear();
        }
      }
    }
    long long i = n - 2;
    long long j = m - 2;
    solve(i, j);
    cout << ans2.size() << "\n";
    for (auto it : ans2) {
      for (auto it2 : it) {
        cout << it2.first << " " << it2.second << " ";
      }
      cout << "\n";
    }
    ans2.clear();
    ans.clear();
  }
}
