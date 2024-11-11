#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long fact[1000007] = {0};
long long expo(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (1ll * res * x) % 1000000007;
    y = y >> 1;
    x = (1ll * x * x) % 1000000007;
  }
  return res;
}
void facto() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 100007; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long npr(long long n, long long r) {
  facto();
  long long res = 1;
  res = fact[n];
  res = (res * (expo(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> v1(n), v2(n), v3(n);
  for (long long i = 0; i < n; i++) {
    cin >> v1[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> v2[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> v3[i];
  }
  long long m;
  cin >> m;
  vector<long long> a(m);
  set<long long> s1, s2, s3;
  for (long long i = 0; i < n; i++) {
    if (v2[i] == 1 || v3[i] == 1) {
      s1.insert(v1[i]);
    }
    if (v2[i] == 2 || v3[i] == 2) {
      s2.insert(v1[i]);
    }
    if (v2[i] == 3 || v3[i] == 3) {
      s3.insert(v1[i]);
    }
  }
  long long x = 0, y = 0, z = 0;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    if (a[i] == 1) {
      if (s1.empty()) {
        cout << "-1 ";
      } else {
        long long t = *s1.begin();
        cout << t << " ";
        if (s1.find(t) != s1.end()) {
          s1.erase(s1.find(t));
        }
        if (s2.find(t) != s2.end()) {
          s2.erase(s2.find(t));
        }
        if (s3.find(t) != s3.end()) {
          s3.erase(s3.find(t));
        }
      }
    } else if (a[i] == 2) {
      if (s2.empty()) {
        cout << "-1 ";
      } else {
        long long t = *s2.begin();
        cout << t << " ";
        if (s1.find(t) != s1.end()) {
          s1.erase(s1.find(t));
        }
        if (s2.find(t) != s2.end()) {
          s2.erase(s2.find(t));
        }
        if (s3.find(t) != s3.end()) {
          s3.erase(s3.find(t));
        }
      }
    } else {
      if (s3.empty()) {
        cout << "-1 ";
      } else {
        long long t = *s3.begin();
        cout << t << " ";
        if (s1.find(t) != s1.end()) {
          s1.erase(s1.find(t));
        }
        if (s2.find(t) != s2.end()) {
          s2.erase(s2.find(t));
        }
        if (s3.find(t) != s3.end()) {
          s3.erase(s3.find(t));
        }
      }
    }
  }
}
