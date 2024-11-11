#include <bits/stdc++.h>
using namespace std;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long Long() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double Double() {
  double x;
  scanf("%lf", &x);
  return x;
}
const int N = 3 * (int)1e5 + 5;
const long long MOD = (int)1e9 + 7;
int prefix[N];
int arr[N];
int main() {
  int n = Int(), m = Int();
  int mx = 0;
  int ind = 0;
  for (int i = 1; i <= n; i++) arr[i] = Int();
  vector<pair<int, int> > v;
  for (int i = 0; i < m; i++) {
    int l = Int(), r = Int();
    v.push_back({l, r});
  }
  for (int i = 1; i <= n; i++) {
    memset(prefix, 0, sizeof prefix);
    for (int j = 0; j < m; j++) {
      if (v[j].first > i or v[j].second < i) {
        prefix[v[j].first]--;
        prefix[v[j].second + 1]++;
      }
    }
    for (int j = 1; j <= n; j++) {
      prefix[j] += prefix[j - 1];
    }
    int mn = 1000000000;
    for (int j = 1; j <= n; j++) {
      mn = min(mn, arr[j] + prefix[j]);
    }
    if (mx < abs(arr[i] - mn)) {
      mx = abs(arr[i] - mn);
      ind = i;
    }
  }
  cout << mx << '\n';
  set<int> st;
  for (int i = 0; i < m; i++) {
    if (v[i].first > ind or v[i].second < ind) {
      st.insert(i + 1);
    }
  }
  cout << st.size() << '\n';
  for (auto j : st) cout << j << ' ';
  cout << '\n';
  return 0;
}
