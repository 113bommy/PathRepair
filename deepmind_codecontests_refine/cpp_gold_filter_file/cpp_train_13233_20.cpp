#include <bits/stdc++.h>
using namespace std;
ifstream fi("test.txt");
ifstream fir("inp.txt");
ofstream fo("out.txt");
const long long MOD = 1e9 + 7;
const long long base = 269;
const int ooi = 1 << 30;
const int N = 1e5 + 5;
long long P(long long x, long long y) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret *= x;
    y /= 2;
    x = x * x;
  }
  return ret;
}
long long GCD(long long a, long long b) { return (b ? GCD(b, a % b) : a); }
long long n, m, q, k, pos, rs, check, t, T, s;
long long maxx = -1e9, minn = 1e9;
pair<long long, long long> a[2 * N];
vector<long long> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long(i) = 0; (i) < (n); (i)++) {
    cin >> a[i].first;
    s += a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n);
  for (long long(i) = 0; (i) < (n); (i)++) {
    long long s1 = s - a[i].first;
    if (i == n - 1 && n - 2 >= 0) {
      if (a[n - 2].first == s1 - a[n - 2].first) {
        ans.push_back(a[i].second);
      }
      continue;
    }
    if (a[n - 1].first == s1 - a[n - 1].first) {
      ans.push_back(a[i].second);
    }
  }
  cout << ans.size() << "\n";
  for (long long(i) = 0; (i) < (ans.size()); (i)++) {
    cout << ans[i] << " ";
  }
}
