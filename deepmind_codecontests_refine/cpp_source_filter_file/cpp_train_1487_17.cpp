#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool cmp(pair<string, int> &a, pair<string, int> &b) {
  return a.second < b.second;
}
void sort(map<string, int> &M) {
  vector<pair<string, int> > A;
  for (auto &it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
  for (auto &it : A) {
    cout << it.first << ' ' << it.second << endl;
  }
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int find(long long int s, long long int n, long long int pos) {
  long long int mid = s + n / 2;
  if (mid == pos) {
    return 1;
  } else if (mid > pos) {
    return 1 + find(mid + 1, n, pos);
  } else {
    return 1 + find(s, mid, pos);
  }
}
long long int fact(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}
long long int num(long long int n, long long int ans) {
  n /= 10;
  if (n == 0) {
    return ans;
  } else {
    return ans + num(n, ans + 1);
  }
}
long long int nof(long long int n) {
  if (n == 1) {
    return 1;
  }
  long long int ans = 2;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i != n) {
        ans += 2;
      } else {
        ans++;
      }
    }
  }
  return ans;
}
long long int getsum(long long int n) {
  long long int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> vec(n + 1);
    for (long long int i = 1; i <= n; i++) {
      cin >> vec[i];
    }
    vector<long long int> ff(n + 1, 0);
    vector<long long int> ans(n + 1, -1);
    vector<long long int> lst(n + 1, 0);
    for (long long int i = 1; i <= n; i++) {
      ff[vec[i]] = max(ff[vec[i]], i - lst[i]);
      lst[vec[i]] = i;
    }
    for (long long int i = 1; i <= n; i++) {
      ff[i] = max(ff[i], n + 1 - lst[i]);
      for (long long int j = ff[i]; j <= n && ans[i] == -1; j++) {
        ans[j] = i;
      }
    }
    for (long long int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
