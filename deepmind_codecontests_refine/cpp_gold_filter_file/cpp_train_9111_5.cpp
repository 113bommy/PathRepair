#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> &i, pair<long long, long long> &j) {
  return i.second < j.second;
}
const long double PI = acos(-1);
const long double EPS = 1e-9;
long long maxn = 2000003;
long long mod = 1e12 + 7;
vector<long long> adj[3005];
vector<pair<long long, long long> > praf(maxn, make_pair(-1, -1));
void print(vector<long long> &a) {
  cout << a.size() << endl;
  for (auto x : a) cout << x << " ";
}
void solve() {
  vector<bool> prime(2 * maxn + 1, true);
  for (int i = 2; i < maxn; i++) {
    long long x = i;
    while (x <= maxn) {
      x += i;
      prime[x] = false;
    }
  }
  vector<long long> vone;
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ones = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == 1) {
      ones++;
      vone.push_back(1);
    }
  if (ones) {
    long long nxt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != 1 && prime[a[i] + 1]) {
        vone.push_back(a[i]);
        print(vone);
        return;
      }
    }
  }
  long long count = 0;
  pair<long long, long long> p;
  long long ans2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] != 1 && a[j] != 1 && prime[a[i] + a[j]]) {
        p = make_pair(a[i], a[j]);
        count = 2;
        break;
      }
    }
  }
  if (count > vone.size()) {
    cout << "2\n";
    cout << p.first << " " << p.second << endl;
    return;
  }
  if (vone.size()) {
    print(vone);
    return;
  }
  cout << "1\n";
  cout << a[0] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  k = 1;
  while (k--) solve();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
