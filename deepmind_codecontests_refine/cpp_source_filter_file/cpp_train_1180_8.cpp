#include <bits/stdc++.h>
using namespace std;
int inf_int = 2e9;
long long inf_ll = 2e18;
const double pi = 3.1415926535898;
template <typename T, typename T1>
void prin(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
template <typename T, typename T1>
void prin(set<pair<T, T1> >& a) {
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << it->first << " " << it->second << "\n";
  }
}
template <typename T>
void prin(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i < a.size() - 1)
      cout << " ";
    else
      cout << "\n";
  }
}
template <typename T>
void prin(set<T>& a) {
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << " ";
  }
}
template <typename T>
void prin_new_line(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
}
template <typename T, typename T1>
void prin_new_line(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
int sum_vec(vector<int>& a) {
  int s = 0;
  for (int i = 0; i < a.size(); i++) {
    s += a[i];
  }
  return s;
}
template <typename T>
T max(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = max(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = min(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
long double s_triangle(long double x1, long double y1, long double x2,
                       long double y2, long double x3, long double y3) {
  return abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}
bool overflow(long long a, long long b) {
  if (a * b / b != a) return true;
  return false;
}
bool debug = 0;
const int maxn = 5e5 + 100;
long long mod = 1e9 + 7;
map<int, int> mp;
void solve() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  int a[n + 1];
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<pair<int, int> > s;
  int r[n + 1];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      r[1] = n + 1;
      for (int e = 1; e <= n; e++) {
        int val = mp[a[e]];
        mp[a[e]]++;
        s.erase({val, a[e]});
        s.insert({val, a[e]});
        if (val + 1 == k) {
          r[1] = e;
          break;
        }
      }
    } else {
      r[i] = r[i - 1];
      if (r[i] < i) {
        r[i] = i;
        int val = mp[a[i]];
        mp[a[i]]++;
        s.erase({val, a[i]});
        s.insert({val + 1, a[i]});
      }
      int val = mp[a[i - 1]];
      s.erase({val, a[i - 1]});
      mp[a[i - 1]]--;
      s.insert({val - 1, a[i - 1]});
      auto it = s.end();
      it--;
      if (it->first >= k) {
      } else {
        int x = r[i];
        r[i] = n + 1;
        if (debug) cout << i << " " << r[i] << "\n";
        for (int e = x + 1; e <= n; e++) {
          int val = mp[a[e]];
          mp[a[e]]++;
          s.erase({val, a[e]});
          s.insert({val + 1, a[e]});
          if (val + 1 >= k) {
            r[i] = e;
            break;
          }
        }
      }
    }
    ans += n - r[i] + 1;
  }
  cout << ans << "\n";
}
int main() {
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
