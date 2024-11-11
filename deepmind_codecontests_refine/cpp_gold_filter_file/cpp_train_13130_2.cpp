#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) return (a + b);
  if (a < b) swap(a, b);
  return gcd(b, a % b);
}
bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
  if (p1.first < p2.first) return true;
  if (p1.first > p2.first) return false;
  if (p1.second.first < p2.second.first) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    pair<int, pair<int, int> > p[n];
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second.first;
      p[i].second.second = i;
    }
    sort(p, p + n, cmp);
    int ans[n], one = 0, two = 0;
    bool check = true;
    for (int i = 0; i < n; i++) {
      if ((one == 0 || p[i].first <= one) && p[i].first > two) {
        ans[p[i].second.second] = 1;
        one = max(one, p[i].second.first);
      } else if ((two == 0 || p[i].first <= two) && p[i].first > one) {
        ans[p[i].second.second] = 2;
        two = max(p[i].second.first, two);
      } else if (p[i].first > one && p[i].first > two) {
        ans[p[i].second.second] = 1;
        one = max(one, p[i].second.first);
      } else
        check = false;
    }
    if (two == 0) {
      check = false;
    }
    if (check) {
      for (int i = 0; i < n; i++) cout << ans[i] << " ";
    } else
      cout << "-1";
    cout << "\n";
  }
}
