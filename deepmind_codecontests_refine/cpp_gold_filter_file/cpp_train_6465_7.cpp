#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
const long long inf = (long long)1e16;
const long double eps = 1e-12;
const long long N = (int)1e5 + 5;
const long long LOGN = 19;
const long double PI = 3.14159265358979323846;
inline long long mul(long long a, long long b, long long m = mod) {
  return (long long)(a * b) % m;
}
inline long long add(long long a, long long b, long long m = mod) {
  a += b;
  if (a >= m) a -= m;
  if (a < 0) a += m;
  return a;
}
inline long long power(long long a, long long b, long long m = mod) {
  if (b == 0) return 1;
  if (b == 1) return (a % m);
  long long x = power(a, b / 2, m);
  x = mul(x, x, m);
  if (b % 2) x = mul(x, a, m);
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (0) {
    freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\input.txt", "r",
            stdin);
    freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\output.txt", "w",
            stdout);
  }
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int diff[n];
  diff[0] = a[0];
  for (int i = 1; i <= n - 1; i++) {
    diff[i] = a[i] - a[i - 1];
  }
  vector<int> ok;
  for (int i = 1; i <= n; i++) {
    int k = i;
    vector<int> poss(k, INT_MIN);
    bool place = true;
    for (int j = 0; j < n; j++) {
      int pos = j % k;
      if (poss[pos] == INT_MIN) {
        poss[pos] = diff[j];
        continue;
      }
      if (poss[pos] != diff[j]) {
        place = false;
        break;
      }
    }
    if (place) {
      ok.push_back(i);
    }
  }
  cout << ok.size() << endl;
  for (auto it : ok) cout << it << ' ';
  return 0;
}
