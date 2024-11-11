#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
long long powm(long long x, long long y, long long p = 1000000007) {
  x %= p;
  long long val = 1;
  while (y) {
    if (y & 1LL) val = (val * x) % p;
    y >>= 1LL;
    x = (x * x) % p;
  }
  return val;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long b, w;
    cin >> b >> w;
    long long x = (1e9) / 2, y = (1e9) / 2;
    vector<pair<long long, long long> > ans;
    if (w > b) {
      if ((x + y) % 2 == 1) x++;
      while (1) {
        if ((x + y) % 2 == 0) {
          if (w == 0) break;
          w--;
        } else {
          if (b == 0) break;
          b--;
        }
        ans.push_back({x, y});
        x++;
      }
      int n = ans.size();
      for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
          if (w == 0) break;
          w--;
          ans.push_back({ans[i].first, ans[i].second - 1});
          if (w == 0) break;
          w--;
          ans.push_back({ans[i].first, ans[i].second + 1});
        }
      }
      if (w == 0 && b == 0) {
        cout << "YES" << '\n';
        for (auto it : ans) cout << it.first << " " << it.second << '\n';
      } else
        cout << "NO" << '\n';
      continue;
    } else {
      if ((x + y) % 2 == 0) x++;
      while (1) {
        if ((x + y) % 2 == 1) {
          if (b == 0) break;
          b--;
        } else {
          if (w == 0) break;
          w--;
        }
        ans.push_back({x, y});
        x++;
      }
      int n = ans.size();
      for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
          if (b == 0) break;
          b--;
          ans.push_back({ans[i].first, ans[i].second - 1});
          if (b == 0) break;
          b--;
          ans.push_back({ans[i].first, ans[i].second + 1});
        }
      }
      if (w == 0 && b == 0) {
        cout << "YES" << '\n';
        for (auto it : ans) cout << it.first << " " << it.second << '\n';
      } else
        cout << "NO" << '\n';
      continue;
    }
  }
}
