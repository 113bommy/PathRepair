#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
unsigned long long power(unsigned long long x, unsigned long long y) {
  if (y == 0)
    return 1;
  else {
    if (y % 2 == 0)
      return power(x * x, y / 2);
    else
      return x * power(x * x, (y - 1) / 2);
  }
}
long long mod_power(long long x, long long y, long long m) {
  long long r = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) r = (r * x) % m;
    y = y / 2;
    x = (x * x) % m;
  }
  return r;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
vector<long long> extended_Euclid(long long a, long long b) {
  vector<long long> v(3);
  if (b == 0) {
    v[0] = a;
    v[1] = 1;
    v[2] = 0;
    return v;
  } else {
    vector<long long> v1 = extended_Euclid(b, a % b);
    v[0] = v1[0];
    v[1] = v1[2];
    v[2] = v1[1] - (a / b) * v1[2];
    return v;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TESTS = 1;
  while (TESTS--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int> >());
    queue<int> q;
    for (int i = 0; i < n; i++) {
      q.push(a[i].second);
    }
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i);
    string ans(n, '0');
    int who = 0;
    while (!s.empty()) {
      while (!s.count(q.front())) {
        q.pop();
      }
      int pos = q.front();
      q.pop();
      vector<int> v;
      set<int>::iterator ip = s.find(pos);
      for (int i = 0; i <= k; i++) {
        v.push_back(*ip);
        if (ip == s.begin()) break;
        ip--;
      }
      ip = next(s.find(pos));
      for (int i = 0; i < k; i++) {
        if (ip == s.end()) break;
        v.push_back(*ip);
        ip++;
      }
      for (auto it : v) {
        s.erase(it);
        ans[it] = '1' + who;
      }
      who += 1;
    }
    cout << ans << endl;
  }
}
