#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7, MAX = 1e18;
vector<long long> prim;
long long power(long long n) {
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    ans = ans * 2;
  }
  return ans;
}
long long isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return 0;
}
long long fact(long long n) {
  long long ans = 1;
  for (long long i = 2; i <= n; i++) {
    ans = ans * i;
  }
  return ans;
}
void SoE(long long n) {
  prim.clear();
  for (long long i = 2; i <= n; i++) {
    if (isprime(i) == 0) {
      prim.push_back(i);
    }
  }
}
bool isPeak(long long n) {}
long long gc(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gc(a - b, b);
  return gc(a, b - a);
}
class pehli {
 public:
  long long name;
  vector<long long> a;
} pehli;
long long fun(long long n) {
  long long ans = 0;
  while (n > 0) {
    long long l = n % 2;
    if (l == 1) ans++;
    n = n / 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  {
    map<long long, long long> make_pair, mp1;
    long long ans = 0, n, l = 0, k = 0, sum = 0, j = 0, m = 0, ans1 = 0,
              ans2 = 0, r = 0;
    cin >> n >> k;
    vector<long long> a(n);
    long long dis = INT_MIN;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (long long i = 1; i < n; i++) {
      dis = max(dis, a[i] - a[i - 1]);
    }
    float d = (float)dis / 2;
    float ans5 = (max(a[0] - 0, k - a[n - 1]));
    if (d > ans5) {
      ans5 = d;
    }
    cout << setprecision(9) << (float)ans5;
  }
  return 0;
}
