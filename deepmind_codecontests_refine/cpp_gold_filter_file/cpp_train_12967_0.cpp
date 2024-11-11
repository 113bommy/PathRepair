#include <bits/stdc++.h>
using namespace std;
const long long MX = 3e5 + 9;
const long double pi = acos(-1);
const long long mod = 1e9 + 7;
bool cmp(int a, int b) { return a > b; }
long long po(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long x = po(a, b / 2);
  x *= x % mod;
  if (b % 2) {
    x *= a % mod;
  }
  return x % mod;
}
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int a[MX];
int cnt[MX];
vector<int> v;
vector<int> num[MX];
int main() {
  int n, m;
  cin >> n >> m;
  int c = n / m;
  int rem = n % m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) {
      v.push_back(i);
    } else
      num[a[i]].push_back(i), cnt[a[i]]++;
  }
  bool ok = 0;
  int q = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > m) {
      ok = 0;
      for (int j = 1; j <= m; j++) {
        if (cnt[j] < c) {
          cnt[j]++;
          a[i] = j;
          ok = 1;
          num[j].push_back(i);
          q++;
          break;
        }
      }
    } else if (cnt[a[i]] < n / m) {
      for (int j = 1; j <= m; j++) {
        if (a[j] > m) {
          continue;
        }
        if (cnt[j] > n / m && cnt[a[i]] < n / m &&
            abs(cnt[j] - cnt[a[i]]) > 1) {
          cnt[j]--;
          cnt[a[i]]++;
          a[num[j].back()] = a[i];
          num[a[i]].push_back(num[j].back());
          num[j].pop_back();
          q++;
        }
      }
    } else if (cnt[a[i]] > n / m) {
      for (int j = 1; j <= m; j++) {
        if (a[j] > m) {
          continue;
        }
        if (cnt[j] < n / m && cnt[a[i]] > n / m &&
            abs(cnt[j] - cnt[a[i]]) > 1) {
          cnt[a[i]]--;
          cnt[j]++;
          a[num[a[i]].back()] = j;
          num[j].push_back(num[a[i]].back());
          num[a[i]].pop_back();
          q++;
        }
      }
    }
  }
  cout << c << " " << q << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
