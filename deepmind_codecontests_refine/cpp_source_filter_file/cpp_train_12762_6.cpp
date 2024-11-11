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
  map<long long, long long> m1, m2, m3;
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
  vector<long long> s1, s2, s3;
  for (long long i = 0; i < n; i++) {
    if (v2[i] == 1 || v3[i] == 1) {
      s1.push_back(v1[i]);
      m1[v1[i]]++;
    }
    if (v2[i] == 2 || v3[i] == 2) {
      s2.push_back(v1[i]);
      m2[v1[i]]++;
    }
    if (v2[i] == 3 || v3[i] == 3) {
      s3.push_back(v1[i]);
      m3[v1[i]]++;
    }
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  sort(s3.begin(), s3.end());
  long long x = 0, y = 0, z = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1) {
      if (x == s1.size()) {
        cout << "-1 ";
      } else {
        if (m1[s1[x]] > 0) {
          cout << s1[x] << " ";
          m1[s1[x]]--;
          m2[s1[x]]--;
          m3[s1[x]]--;
          x++;
        } else {
          i--;
          x++;
        }
      }
    } else if (a[i] == 2) {
      if (y == s2.size()) {
        cout << "-1 ";
      } else {
        if (m2[s2[y]] > 0) {
          cout << s2[y] << " ";
          m1[s2[y]]--;
          m2[s2[y]]--;
          m3[s2[y]]--;
          y++;
        } else {
          y++;
          i--;
        }
      }
    } else {
      if (z == s3.size()) {
        cout << "-1 ";
      } else {
        if (m3[s3[z]] > 0) {
          cout << s3[z] << " ";
          m1[s3[z]]--;
          m2[s3[z]]--;
          m3[s3[z]]--;
          z++;
        } else {
          z++;
          i--;
        }
      }
    }
  }
}
