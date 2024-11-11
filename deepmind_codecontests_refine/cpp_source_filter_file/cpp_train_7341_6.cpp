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
const int maxn = 2e5 + 7;
void solve() {
  int n;
  cin >> n;
  int a[n];
  map<int, int> mp;
  map<int, int> mp1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    mp1[a[i]] = 0;
  }
  int ans = 0;
  int b[200];
  for (int i = 0; i < n; i++) {
    for (int e = 0; e < n; e++) {
      if (i == e) continue;
      if (a[i] == 0 && a[e] == 0) {
        ans = max(ans, mp[0]);
        continue;
      }
      int cur = 2;
      int z = 1;
      mp1[a[i]]++;
      mp1[a[e]]++;
      b[0] = a[i];
      b[1] = a[e];
      while (1) {
        int x = b[z] + b[z - 1];
        if (mp.find(x) != mp.end()) {
          mp1[x]++;
          if (mp1[x] > mp[x]) {
            mp1[x] = 0;
            for (int e = 0; e <= z; e++) {
              mp1[b[e]] = 0;
            }
            break;
          }
          b[++z] = x;
          cur++;
        } else {
          for (int e = 0; e <= z; e++) {
            mp1[b[e]] = 0;
          }
          break;
          break;
        }
        ans = max(ans, cur);
      }
    }
  }
  cout << ans;
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
