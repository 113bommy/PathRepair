#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 5;
const long long MAX = 1e18;
template <typename T>
T gcd(T x, T y) {
  return y == 0 ? x : gcd(y, x % y);
}
template <typename T>
T lcm(const T &a, const T &b) {
  return (a * b) / gcd(a, b);
}
void vlcout(vector<long long> &v) {
  long long i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void vicout(vector<int> &v) {
  long long i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void vpcout(vector<pair<long long, long long> > &v) {
  long long i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}
void acout(long long *a, long long n) {
  long long i;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long kpow(long long a, long long b) {
  long long ct = 0;
  long long k = 1;
  while (ct < b) {
    k *= a;
    ct++;
  }
  return k;
}
int pows(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (1LL * (ans)*a) % mod;
    }
    a = (1LL * a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long klog(long long x, long long b) {
  long long ct = 0;
  long long k = 1;
  while (k <= x) {
    k *= b;
    ct++;
  }
  return ct - 1;
}
void freq(long long *a, long long n, vector<long long> &fre) {
  long long i;
  for (i = 0; i < n; i++) {
    fre[a[i]]++;
  }
}
template <typename T>
void pfact(vector<pair<T, T> > &v, T k) {
  T i;
  for (i = 2; i <= sqrt(k); i++)
    if (k % i == 0) {
      T x = 0;
      while (k % i == 0) {
        k /= i;
        x++;
      }
      v.push_back(make_pair(i, x));
    }
  if (k != 1) {
    v.push_back(make_pair(k, 1));
  }
}
void sieve(long long *spf) {
  spf[1] = 1;
  for (int i = 2; i < N; i++) spf[i] = i;
  for (int i = 4; i < N; i += 2) spf[i] = 2;
  for (int i = 3; i * i < N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < N; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<long long> getfactorization(long long x, vector<long long> spf) {
  vector<long long> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
bool sortcol(const vector<long long> &v1, const vector<long long> &v2) {
  return v1[0] < v2[0];
}
int main() {
  long long i, j, n, s;
  cin >> n >> s;
  s--;
  long long a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (a[0] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (a[s] == 0 && b[s] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (a[s] == 1) {
    cout << "YES" << endl;
    return 0;
  } else {
    for (i = 0; i < n; i++) {
      if (a[i] == 1 && b[i] == 1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
