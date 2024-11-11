#include <bits/stdc++.h>
using namespace std;
const int nmax = 300500;
int dp[nmax];
int c[nmax];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  dp[1] = 0;
  c[1] = 0;
  for (int i = 2; i < nmax; ++i) {
    dp[i] = dp[i - 1];
    int n = i;
    int cnt = 1;
    for (int d = 2; d * d <= n; ++d) {
      if (n % d == 0) {
        int a = 0;
        while (n % d == 0) {
          n /= d;
          ++a;
        }
        cnt *= (a + 1);
      }
    }
    if (n != 1) {
      cnt *= 2;
    }
    c[i] = cnt - 1;
    dp[i] += cnt - 1;
  }
  int n, k;
  cin >> n >> k;
  if (dp[n] < k) {
    cout << "No\n";
    return 0;
  }
  for (int i = 1;; ++i) {
    if (dp[i] >= k) {
      n = i;
      break;
    }
  }
  if (dp[n] == k) {
    cout << "Yes\n";
    cout << n << "\n";
    for (int i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    cout << "\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (dp[n] - c[i] - (n / i) + 1 == k) {
      cout << "Yes\n";
      cout << n - 1 << "\n";
      for (int j = 1; j <= n; ++j) {
        if (i == j) {
          continue;
        }
        cout << j << " ";
      }
      cout << "\n";
      return 0;
    }
  }
  vector<pair<int, int> > knap;
  for (int i = 2; i <= n; ++i) {
    if (c[i] == 1) {
      knap.push_back({i, n / i});
    }
  }
  vector<bool> alive(n + 1, true);
  int w = dp[n] - k;
  int cnt = 0;
  for (int i = 0; i < (int)(knap).size(); ++i) {
    if (knap[i].second == 1) {
      ++cnt;
    }
  }
  if (w <= cnt) {
    for (int i = 0; i < w; ++i) {
      alive[knap[(int)(knap).size() - i - 1].first] = false;
    }
  } else {
    for (int i = 0; i < (int)(knap).size(); ++i) {
      if (knap[i].second > w) {
        continue;
      }
      if (knap[i].second == 1) {
        assert(false);
      }
      alive[knap[i].first] = false;
      w -= knap[i].second;
      if (w <= cnt) {
        for (int j = 0; j < w; ++j) {
          alive[knap[(int)(knap).size() - j - 1].first] = false;
        }
        goto d;
      }
    }
  }
d:;
  cout << "Yes\n";
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (alive[i]) {
      ++cnt;
    }
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; ++i) {
    if (alive[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
