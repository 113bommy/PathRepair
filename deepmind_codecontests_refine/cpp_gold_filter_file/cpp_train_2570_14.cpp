#include <bits/stdc++.h>
const int mo = 1000000007;
const int inf = 0x3f3f3f3f;
double pi = 3.14159265358979323846;
double e = 2.71828182845904523536;
using namespace std;
long long a[200005], b[200005];
set<long long> s;
long long n, m, k;
long long ans = 0;
int main() {
  cin >> n >> m;
  k = n / m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i] % m]++;
  }
  for (int i = 0; i < m; i++)
    if (b[i] < k) s.insert(i);
  for (int i = 0; i < n; i++) {
    if (b[a[i] % m] > k) {
      b[a[i] % m]--;
      set<long long>::iterator it;
      it = s.lower_bound(a[i] % m);
      if (it != s.end()) {
        ans += (*it - a[i] % m);
        a[i] += (*it - a[i] % m);
        b[*it]++;
        if (b[*it] == k) s.erase(it);
      } else {
        ans += (m - a[i] % m + *s.begin());
        a[i] += (m - a[i] % m + *s.begin());
        b[*s.begin()]++;
        if (b[*s.begin()] == k) s.erase(s.begin());
      }
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i];
    cout << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
