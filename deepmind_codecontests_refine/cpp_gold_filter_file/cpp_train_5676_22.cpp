#include <bits/stdc++.h>
const double eps = 1e-10;
const float epsf = 1e-6;
using namespace std;
inline long long int __gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  }
  long long int tempa, tempb;
  while (1) {
    if (a % b == 0)
      return b;
    else {
      tempa = a;
      tempb = b;
      a = tempb;
      b = tempa % tempb;
    }
  }
}
inline int compfloat(float& x, float& y) {
  if (fabs(x - y) < epsf)
    return 0;
  else if (x - y > 0)
    return 1;
  return -1;
}
inline int compdouble(double x, double y) {
  if (fabs(x - y) < eps)
    return 0;
  else if (x - y > 0)
    return 1;
  else
    return -1;
}
bool prime(long long int k) {
  for (long long int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      return false;
    }
  return true;
}
void pdash(int n = 1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
long long int power(long long int x, long long int y) {
  long long int result = 1;
  while (y > 0) {
    if (y & 1) {
      result = (result * x);
    }
    y = y >> 1;
    x = (x * x);
  }
  return result;
}
long long int power(long long int x, long long int y, long long int z) {
  long long int result = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % z;
    }
    y = y >> 1;
    x = (x * x) % z;
  }
  return result;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrF(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int f[n + 1];
  f[0] = 1;
  for (long long int i = 1; i <= n; i++) f[i] = f[i - 1] * i % p;
  return (f[n] * modInverse(f[r], p) % p * modInverse(f[n - r], p) % p) % p;
}
void cordinate_compression(vector<int>& v) {
  vector<int> p = v;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 0; i < (int)((v).size()); i++)
    v[i] = (int)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
}
long long int lin, rin, value;
long long int ans = 0;
long long int a;
long long int queries(vector<long long int>& prefix, long long int m,
                      vector<pair<long long int, int> >& arr, int r,
                      int& llind) {
  if (r == 0) {
    llind = 0;
    return a;
  }
  int l = 1;
  int mid;
  int index;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (mid * arr[mid].first - prefix[mid] <= m) {
      l = mid;
    } else
      r = mid;
  }
  if (r * arr[r].first - prefix[r] <= m) {
    index = r;
  } else
    index = l;
  m -= index * arr[index].first - prefix[index];
  llind = index;
  return min(arr[index].first + (m / index), a);
}
void solve() {
  int n;
  long long int cf, cm, m, mm;
  cin >> n >> a >> cf >> cm >> m;
  vector<long long int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }
  vector<pair<long long int, int> > arr(n + 1);
  for (int i = 1; i <= n; i++) {
    arr[i].first = vec[i];
    arr[i].second = i;
  }
  sort(arr.begin() + 1, arr.end());
  vector<long long int> suffix(n + 1, 0), prefix(n + 1, 0);
  suffix[n] = arr[n].first;
  for (int i = n - 1; i; i--) suffix[i] += suffix[i + 1] + arr[i].first;
  for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i].first;
  int lind;
  long long int que, queans;
  que = queries(prefix, m, arr, n, lind);
  ans = cm * que;
  lin = lind;
  rin = n + 1;
  queans = que;
  for (int i = n; i; i--) {
    mm = m;
    mm -= ((n + 1) - i) * a - suffix[i];
    if (mm < 0) continue;
    que = queries(prefix, mm, arr, i - 1, lind);
    if (ans < ((n + 1) - i) * cf + cm * que) {
      ans = ((n + 1) - i) * cf + cm * que;
      lin = lind;
      rin = i;
      queans = que;
    }
  }
  for (int i = 1; i <= lin; i++) {
    arr[i].first = queans;
  }
  for (int i = (int)rin; i <= n; i++) {
    arr[i].first = a;
  }
  for (int i = 1; i <= n; i++) {
    vec[arr[i].second] = arr[i].first;
  }
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) cout << vec[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
