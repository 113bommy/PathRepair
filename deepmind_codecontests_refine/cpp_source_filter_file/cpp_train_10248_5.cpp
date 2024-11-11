#include <bits/stdc++.h>
using namespace std;
int issorted(long long a[], long long n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) return 0;
  }
  return 1;
}
int isprime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int ispalindrome(string s, int n) {
  int l = 0, h = n - 1;
  while (l < h) {
    if (s[l++] != s[h--]) return 0;
  }
  return 1;
}
bool sortinrev(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n), w(m);
  map<long long, long long> make_pair;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < m; i++) {
    cin >> w[i];
    make_pair[w[i]] = v[w[i] - 1];
  }
  long long s = 0, t;
  for (long long i = 0; i < n; i++) {
    if (make_pair.count(i + 1) == 0) {
      s += v[i];
    }
  }
  t = 0;
  long long f = 0;
  auto it = make_pair.rbegin();
  long long maxi = INT_MIN;
  long long pp = 0;
  for (auto it : make_pair) {
    if (it.second > s) {
      if (!pp) t = s, pp = 1;
      s = it.second;
      f = it.first;
    }
  }
  if (f != 0) {
    make_pair.erase(f);
  }
  s += t;
  for (auto it : make_pair) {
    if (s > it.second)
      s += s;
    else
      s += it.second;
  }
  cout << s + t;
  return 0;
}
