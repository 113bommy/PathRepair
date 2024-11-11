#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
map<long long, int> m;
vector<long long> v;
map<long long, int> m1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long x, k;
  cin >> x >> k;
  int i;
  for (i = 0; i < n; i++) {
    long long c;
    cin >> c;
    m[c]++;
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  for (i = 0; i < n; i++) {
    long long cur = v[i];
    if (k == 0) {
      long long bd = (cur + x - 1) / x;
      long long le = cur;
      long long ri = x * (bd)-1;
      if (cur % x == 0) {
        continue;
      }
      vector<long long>::iterator it = lower_bound(v.begin(), v.end(), le);
      vector<long long>::iterator itu = upper_bound(v.begin(), v.end(), ri);
      cnt = cnt + (1ll * distance(it, itu));
    } else {
      long long bd = (cur + x - 1) / x;
      long long le = x * (bd + k - 1);
      long long ri = x * (bd + k) - 1;
      vector<long long>::iterator it = lower_bound(v.begin(), v.end(), le);
      vector<long long>::iterator itu = upper_bound(v.begin(), v.end(), ri);
      cnt = cnt + (1ll * distance(it, itu));
    }
  }
  cout << cnt << endl;
  return 0;
}
