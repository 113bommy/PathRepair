#include <bits/stdc++.h>
using namespace std;
long long n, ans, con;
vector<int> ar[100005];
pair<int, int> v[100005];
bool has(vector<int> vec) {
  int mn = vec[0];
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] > mn) return true;
    mn = min(mn, vec[i]);
  }
  return false;
}
int ser(int x, int n) {
  int k = 0;
  int i = n / 2;
  i = i ? i : 1;
  for (; i >= 1; i /= 2) {
    while (k + i < n && v[i + k].first <= x) k += i;
  }
  return k - con + 1;
}
void mnmx(vector<int> vec, int i) {
  v[i].second = vec[0];
  v[i].first = vec[0];
  for (int j = 1; j < vec.size(); ++j) {
    v[i].second = min(v[i].second, vec[j]);
    v[i].first = max(v[i].first, vec[j]);
  }
  if (vec.size() == 0) v[i].first = INT_MAX, v[i].second = INT_MAX;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      int num;
      cin >> num;
      ar[i].push_back(num);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!has(ar[i]))
      mnmx(ar[i], i);
    else
      v[i].first = -1, v[i].second = -1, con++;
  }
  sort(v, v + n);
  ans = n * n;
  for (int i = 0; i < n; ++i) {
    if (v[i].first != -1) ans -= ser(v[i].second, n);
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
