#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b < a) {
    long long int temp = a;
    a = b;
    b = temp;
  }
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int max(long long int a, long long int b) { return a > b; }
long long int lcm(long long int a, long long int b) {
  return (a * b / gcd(a, b));
}
long long int fact(long long int x) {
  long long int ans = 1;
  if (x == 0) {
    return 1;
  }
  while (x > 0) {
    ans = (ans * x) % 1000000007;
    x--;
  }
  return ans % 1000000007;
}
long long int comb(long long int n, long long int r) {
  long long int x = fact(r), y = fact(n - r);
  x = (x * y) % 1000000007;
  if (fact(n) > x) return fact(n) / x;
  return (fact(n) + 1000000007) / x;
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans = ans;
    }
    b /= 2;
    a *= a;
    a = a;
  }
  return ans;
}
vector<long long int> getbinary(long long int x) {
  vector<long long int> bin(20000, 0);
  long long int iter = 0;
  while (x > 0) {
    if (x % 2 == 1) {
      bin[iter] = 1;
    } else {
      bin[iter] = 0;
    }
    iter++;
    x /= 2;
  }
  return bin;
}
void func(long long int k, long long int t, long long int* a, long long int n) {
  a[0] += t;
  long long int i, o = 1, j = 0;
  for (i = 1; i < n; i++) {
    if (a[i] >= a[j]) {
      a[i] += t;
      j++;
    } else {
      if (o < k) {
        a[i] += t;
        o++;
      } else {
        a[i] = a[j] + t;
        j++;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int k[3], t[3], n, i, x = 0;
  cin >> k[0] >> k[1] >> k[2];
  cin >> t[0] >> t[1] >> t[2];
  cin >> n;
  long long int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (i = 0; i < 3; i++) {
    func(k[i], t[i], a, n);
  }
  for (i = 0; i < n; i++) {
    if (a[i] - b[i] > x) x = a[i] - b[i];
  }
  cout << x << endl;
}
