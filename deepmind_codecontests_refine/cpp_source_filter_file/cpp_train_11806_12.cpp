#include <bits/stdc++.h>
using namespace std;
template <typename T, typename L>
inline bool smax(T &x, L y) {
  return x < y ? (x = y, true) : false;
}
template <typename T, typename L>
inline bool smin(T &x, L y) {
  return y < x ? (x = y, true) : false;
}
constexpr int MAXN = 128;
int n, m;
pair<string, int> a[MAXN];
int b[MAXN];
vector<int> att, def;
vector<int> num;
int nps[MAXN];
int ps[MAXN], aps[MAXN];
int mx, sz = -1;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    if (a[i].first == "ATK") {
      att.push_back(a[i].second);
    } else {
      def.push_back(a[i].second);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    num.push_back(b[i]);
  }
  sort(num.begin(), num.end());
  sort(def.begin(), def.end());
  sort(att.begin(), att.end());
  sort(b, b + m);
  for (int i = 0; i < m; i++) {
    if (i)
      ps[i] = b[i] + ps[i - 1];
    else
      ps[i] = b[i];
  }
  for (int i = 0; i < (int)att.size(); i++) {
    if (i)
      aps[i] = aps[i - 1] + att[i];
    else
      aps[i] = att[i];
  }
  for (int i = 1; i <= (int)att.size(); i++) {
    bool can = true;
    int p = i - 1;
    for (int j = m - 1; j >= m - i; j--) {
      if (b[j] < att[p++]) {
        can = false;
        break;
      }
    }
    if (can) {
      smax(mx, ps[m - 1] - ps[m - i - 1] - aps[i - 1]);
    }
  }
  for (int i = 0; i < (int)def.size(); i++) {
    int p = upper_bound(num.begin(), num.end(), def[i]) - num.begin();
    if (p == (int)num.size()) {
      return cout << mx << '\n', false;
    }
    num.erase(num.begin() + p);
  }
  for (int i = 0; i < (int)num.size(); i++) {
    if (i)
      nps[i] = num[i] + nps[i - 1];
    else {
      nps[i] = num[i];
    }
  }
  sz = (int)num.size();
  for (int i = 0; i < (int)att.size(); i++) {
    if (num.empty()) {
      return cout << mx << '\n', false;
    }
    int p = lower_bound(num.begin(), num.end(), att[i]) - num.begin();
    if (p == (int)num.size()) {
      return cout << mx << '\n', false;
    }
    num.erase(num.begin() + p);
  }
  smax(mx, nps[sz - 1] - aps[att.size() - 1]);
  return cout << mx << '\n', false;
}
