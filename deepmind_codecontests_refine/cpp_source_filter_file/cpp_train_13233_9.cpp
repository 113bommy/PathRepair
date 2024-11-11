#include <bits/stdc++.h>
using namespace std;
long long a[1000007];
vector<long long> v;
bool sortinrev(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first > b.first);
}
void seive() {
  for (long long i = 0; i <= 1000000; i++) a[i] = 1;
  a[0] = a[1] = 0;
  for (long long i = 2; i <= 1000; i++) {
    if (a[i] == 1) {
      v.push_back(i);
      for (long long j = 2 * i; j <= 1000000; j += i) a[j] = 0;
    }
  }
  for (long long i = 1001; i <= 1000000; i++) {
    if (a[i] == 1) v.push_back(i);
  }
}
long long nCr(long long n, long long r) {
  long long ans = 1;
  long long k = 2;
  if (n - r < r)
    k = n - r;
  else
    k = r;
  for (long long i = n; i >= n - k; i--) {
    ans *= i;
    if (ans % k == 0 && k > 1) {
      ans /= k;
      k--;
    }
  }
  while (k > 1) {
    ans /= k;
    k--;
  }
  return ans;
}
long long fpow(long long a, long long n) {
  if (n == 1) return a;
  if (n % 2) return (a % 1000000007 * fpow(a, n - 1) % 1000000007) % 1000000007;
  return (fpow(a, n / 2) % 1000000007 * fpow(a, n / 2) % 1000000007) %
         1000000007;
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  map<long long, vector<long long> > mp;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i + 1);
    sum += a[i];
  }
  long long b[n];
  for (long long i = 0; i < n; i++) {
    b[i] = sum - a[i];
  }
  set<long long> v;
  for (long long i = 0; i < n; i++) {
    if (mp.find(b[i] - a[i]) != mp.end()) {
      for (long long j = 0; j < mp[b[i] - a[i]].size(); j++) {
        if (a[mp[b[i] - a[i]][j] - 1] != i) v.insert(mp[b[i] - a[i]][j]);
      }
    }
  }
  cout << v.size() << "\n";
  for (set<long long>::iterator x = v.begin(); x != v.end(); x++) {
    cout << *x << " ";
  }
  return 0;
}
