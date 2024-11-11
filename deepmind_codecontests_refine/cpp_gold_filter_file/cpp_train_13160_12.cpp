#include <bits/stdc++.h>
using namespace std;
long long pw(long long x, long long a) {
  if (a == 0) return 1;
  long long t = pw(x, a / 2);
  if (a % 2 == 0)
    return (t * t);
  else
    return (t * t * x);
}
bool prime(int x) {
  if (x < 2) return false;
  for (int i = 2; i <= sqrt(x); i++) {
    if ((x % i) == 0) return false;
  }
  return true;
}
vector<pair<long long, long long> > a;
map<int, long long> m;
string ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(a.begin(), a.end());
  long long f = a[0].first;
  m[a[0].second] = f;
  f++;
  for (int i = 1; i < n; i++) {
    f = max(f, a[i].first);
    m[a[i].second] = f;
    f++;
  }
  for (int i = 0; i < n; i++) {
    cout << m[i] << ' ';
  }
  cout << endl;
  return 0;
}
