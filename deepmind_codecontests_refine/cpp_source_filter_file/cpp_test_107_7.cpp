#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long int mminvprime(long long int a, long long int b) {
  return expo(a, b - 2, b);
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
vector<long long int> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a;
  cin >> a;
  long long int b;
  cin >> b;
  vector<long long int> v;
  if (abs(a - b) > 1 || (n - 2 + 1) / 2 < a || (n - 2 + 1) / 2 < b ||
      (n - 2) < (a + b)) {
    cout << "-1\n";
    return;
  }
  long long int mn = min(a, b);
  long long int points = n;
  if (a > b) {
    long long int i = 1;
    while (mn >= 0 && points > 0) {
      v.push_back(i);
      v.push_back(n - i + 1);
      points -= 2;
      i++;
      mn--;
    }
    long long int start = i - 1;
    while ((n - i + 1) > start && points > 0) {
      v.push_back(n - i + 1);
      points -= 1;
      i++;
    }
  } else if (b > a) {
    long long int i = 1;
    while (mn >= 0 && points > 0) {
      v.push_back(n - i + 1);
      v.push_back(i);
      points -= 2;
      i++;
      mn--;
    }
    long long int end = n - i + 1 + 1;
    while (i < end && points > 0) {
      v.push_back(i);
      points -= 1;
      i++;
    }
  } else {
    long long int i = 1;
    while (mn >= 0 && points > 0 && (a + b) > 0) {
      v.push_back(n - i + 1);
      v.push_back(i);
      points -= 2;
      i++;
      mn--;
    }
    long long int start = i - 1;
    while ((n - i + 1) > start && points > 0) {
      v.push_back(n - i + 1);
      points -= 1;
      i++;
    }
  }
  for (auto it : v) {
    cout << it << ' ';
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
