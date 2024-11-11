#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int P[100009][21], ans[100009], n, k;
string s;
void build_suf() {
  for (int i = 0; i < n; i++) P[i][0] = s[i] - 'a';
  for (int i = 1; i <= k; i++) {
    vector<pair<pair<int, int>, int> > v;
    for (int j = 0; j < n; j++) {
      int left = P[j][i - 1], rigt;
      if (j + (1 << (i - 1)) >= n)
        rigt = -1;
      else
        rigt = P[j + (1 << (i - 1))][i - 1];
      v.push_back(make_pair(make_pair(left, rigt), j));
    }
    sort(v.begin(), v.end());
    P[v[0].second][i] = 0;
    int c = 0;
    for (int j = 1; j < v.size(); j++) {
      if (v[j].first.first != v[j - 1].first.first or
          v[j].first.second != v[j - 1].first.second)
        ++c;
      P[v[j].second][i] = c;
    }
  }
  vector<pair<int, int> > g;
  for (int i = 0; i < n; i++) g.push_back(make_pair(P[i][k], i));
  sort(g.begin(), g.end());
  for (int i = 0; i < g.size(); i++) ans[i] = g[i].second;
}
int lcp[100009], arr[100009], l[100009], r[100009];
void build_lcp() {
  for (int i = 0; i < n - 1; i++) {
    int a = ans[i], b = ans[i + 1], res = 0;
    for (int j = k; j >= 0; j--) {
      if (a < n and b < n and P[a][j] == P[b][j]) {
        a += (1 << j);
        b += (1 << j);
        res += (1 << j);
      }
    }
    lcp[i] = res;
  }
}
int main() {
  cin >> s;
  n = s.size();
  k = log2(n);
  build_suf();
  build_lcp();
  stack<int> s;
  int a = n - 1;
  for (int i = 1; i <= a; i++) arr[i] = lcp[i - 1];
  arr[0] = -1000000007;
  s.push(0);
  for (int i = 1; i <= a; i++) {
    while (!s.empty() and arr[s.top()] >= arr[i]) {
      r[s.top()] = i - 1;
      s.pop();
    }
    l[i] = s.top() + 1;
    s.push(i);
    r[i] = a;
  }
  long long ans = 0;
  for (int i = 1; i <= a; i++) {
    long long k1 = (r[i] - i + 1LL);
    long long k2 = (i - l[i] + 1LL);
    ans += k1 * k2 * arr[i] * 1LL;
  }
  cout << ans + (n * (n + 1LL) / 2) << endl;
  return 0;
}
