#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long int C(int n, int k) {
  long long ans = 1;
  k = k > n - k ? n - k : k;
  int j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= n / j;
    } else if (ans % j == 0) {
      ans = ans / j * n;
    } else {
      ans = (ans * n) / j;
    }
  }
  return ans;
}
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0)
    return (b);
  else
    return (gcd(b % a, a));
}
long long int powmod(long long int a, long long int b, long long int m) {
  long long int res = 1;
  a %= m;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
  }
  return res;
}
int countSetBits(long long int n) {
  unsigned int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
int main() {
  int n, t;
  cin >> n >> t;
  string a, b;
  cin >> a >> b;
  bool same[n];
  int count = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) {
      same[i] = true;
      count++;
    } else {
      same[i] = false;
    }
  }
  if ((t == 0 and count != n) or (n - count) / 2 + (n - count) % 2 > t) {
    cout << -1 << endl;
    return 0;
  } else if (t == 0 and count == n) {
    cout << a << endl;
    return 0;
  }
  int flag = 0;
  string ans = a;
  int cur = 0;
  int diff = n - count;
  int index = -1;
  if (diff <= t) {
    for (int i = 0; i < n; i++) {
      if (same[i] == false) {
        char c = 'a';
        while (c == a[i] or c == b[i]) {
          c++;
        }
        ans[i] = c;
      }
    }
  } else {
    int count = (diff - t) * 2;
    for (int i = 0; i < n; i++) {
      if (same[i] == false) {
        if (flag) {
          ans[i] = a[i];
        } else {
          ans[i] = b[i];
        }
        flag = 1 - flag;
        count--;
        index = i;
        if (count == 0) {
          break;
        }
      }
    }
    for (int i = index + 1; i < n; i++) {
      if (same[i] == false) {
        char c = 'a';
        while (c == a[i] or c == b[i]) {
          c++;
        }
        ans[i] = c;
      }
    }
  }
  cur = min(diff, t);
  if (cur == t) {
    cout << ans << endl;
    return 0;
  } else {
    for (int i = 0; i < n; i++) {
      if (same[i] == true) {
        if (a[i] == 'a') {
          ans[i] = 'b';
        } else {
          ans[i] = 'a';
        }
        cur++;
        if (cur == t) {
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
