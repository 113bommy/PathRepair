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
double s_triangle(double x1, double y1, double x2, double y2, double x3,
                  double y3) {
  return abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}
bool overflow(long long a, long long b) {
  if (a * b / b != a) return true;
  return false;
}
bool debug = 0;
const int maxn = 2e5 + 70;
set<int> s[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (y == 0) {
      int ans = 0;
      for (int e = 1; e * e <= x; e++) {
        if (x % e == 0) {
          if (x / e == e) {
            s[e].insert(i);
            ans++;
          } else {
            s[e].insert(i);
            s[x / e].insert(i);
            ans = ans + 2;
          }
        }
      }
      cout << ans << "\n";
    } else {
      int ans = 0;
      for (int e = 1; e * e <= x; e++) {
        if (x % e == 0) {
          if (x / e == e) {
            if (s[e].lower_bound(i - y) == s[e].end()) {
              ans++;
            }
            s[e].insert(i);
          } else {
            if (s[e].lower_bound(i - y) == s[e].end()) {
              ans++;
            }
            if (s[x / e].lower_bound(i - y) == s[x / e].end()) {
              ans++;
            }
            s[e].insert(i);
            s[x / e].insert(i);
          }
        }
      }
      cout << ans << "\n";
    }
  }
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
