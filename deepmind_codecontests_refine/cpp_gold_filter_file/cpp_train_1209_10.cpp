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
  cout << endl;
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
const int maxn = 1e6 + 7;
long long mod = 1e9 + 7;
int len;
bool cmp(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
  if (a.first.first / len == b.first.first / len) {
    return (a.first.second < b.first.second);
  } else {
    return (a.first.first < b.first.first);
  }
}
long long cnt[maxn];
void solve() {
  int n, t;
  scanf("%d %d", &n, &t);
  len = sqrt(n) + 1;
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<pair<pair<int, int>, int> > b;
  for (int i = 0; i < t; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    b.push_back({{l, r}, i});
  }
  sort(b.begin(), b.end(), cmp);
  long long cur = 0;
  vector<long long> ans(t);
  for (int i = b[0].first.first; i <= b[0].first.second; i++) {
    int x = a[i];
    cur += (2 * cnt[x] + 1) * x;
    cnt[x]++;
  }
  ans[b[0].second] = cur;
  int l = b[0].first.first, r = b[0].first.second;
  for (int i = 1; i < b.size(); i++) {
    while (b[i].first.first < l) {
      l--;
      cur += (cnt[a[l]] << 1 | 1) * a[l];
      cnt[a[l]]++;
    }
    while (b[i].first.first > l) {
      cnt[a[l]]--;
      cur = cur - (cnt[a[l]] << 1 | 1) * a[l];
      l++;
    }
    while (b[i].first.second > r) {
      r++;
      cur += (cnt[a[r]] << 1 | 1) * a[r];
      cnt[a[r]]++;
    }
    while (b[i].first.second < r) {
      cnt[a[r]]--;
      cur = cur - (cnt[a[r]] << 1 | 1) * a[r];
      r--;
    }
    ans[b[i].second] = cur;
  }
  for (int i = 0; i < t; i++) {
    printf("%I64d\n", ans[i]);
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
