#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int pow1(long long int x, long long int n, long long int m) {
  long long int result = 1;
  while (n > 0) {
    x %= m;
    if (n % 2 == 1) result = (result * x) % m;
    x = (x * x) % m;
    n = n / 2;
  }
  return result;
}
const int size = 1e6 + 1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  int a[n], b[n];
  vector<int> v;
  set<int> my1, my2;
  for (int i = int(0); i < int(n); i++) cin >> a[i];
  for (int i = int(0); i < int(n); i++) cin >> b[i];
  for (int i = int(0); i < int(n); i++) {
    if (my1.find(b[i]) != my1.end())
      my1.erase(b[i]);
    else
      my2.insert(b[i]);
    if (my2.find(a[i]) != my2.end())
      my2.erase(a[i]);
    else
      my1.insert(a[i]);
    if (my2.empty() and my1.empty()) v.push_back(i);
  }
  if (v.size() < k) {
    cout << "NO";
    return 0;
  }
  int K = 0;
  string s(n, ' ');
  int m = v.size();
  for (int i = int(0); i < int(m); i++) {
    int l, r;
    if (i == 0)
      l = 0;
    else
      l = v[i - 1] + 1;
    if (i == m - 1)
      r = n - 1;
    else
      r = v[i];
    for (int j = l; j <= r; j++) s[a[j] - 1] = 'a' + K;
    if (K < k - 1) K++;
  }
  cout << "YES\n";
  cout << s;
  return 0;
}
