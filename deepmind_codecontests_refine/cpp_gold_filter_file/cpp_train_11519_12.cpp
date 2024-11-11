#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.fi << ", " << p.se << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long int l = v.size();
  for (long long int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
long long int gcd(long long int a, long long int b) {
  if (b < a) {
    int temp = a;
    a = b;
    b = temp;
  }
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b / gcd(a, b));
}
vector<long long int> getprimes() {
  vector<long long int> pl(101, 1);
  for (int i = 2; i <= 100; i++) {
    if (pl[i] == 1) {
      for (int j = 2 * i; j <= 100; j += i) {
        pl[j] = 0;
      }
    }
  }
  return pl;
}
long long int primefactorise(int n) {
  if (n == 1) {
    return 1;
  }
  long long int ans = n;
  while (n % 2 == 0) {
    n = n / 2;
    if (n != 1) {
      ans += n;
    }
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      n = n / i;
      if (n != 1) {
        ans += n;
      }
    }
  }
  ans += 1;
  return ans;
}
long long int power(long long int a, long long int b, long long int m) {
  a %= m;
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans = ans % m;
    }
    b /= 2;
    a *= a;
    a = a % m;
  }
  return ans % m;
}
vector<long long int> getbinary(long long int first) {
  vector<long long int> bin(8, 0);
  long long int iter = 0;
  while (first > 0) {
    if (first % 2 == 0) {
      bin[iter] = 0;
    } else {
      bin[iter] = 1;
    }
    first /= 2;
    iter++;
  }
  return bin;
}
long long int dist(pair<long long int, long long int> a,
                   pair<long long int, long long int> b) {
  return (b.first - a.first) * (b.first - a.first) +
         (b.second - a.second) * (b.second - a.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(20);
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a[n];
  long long int ans = 1e18;
  for (int i = 1; i <= n; i++) {
    cin >> a[i - 1];
    if (i % 2) {
      ans = min(ans, a[i - 1]);
    }
  }
  if (!(n % 2)) {
    cout << 0 << endl;
    return 0;
  }
  long long int temp = n / 2 + 1;
  ans = min(ans, m / temp * k);
  cout << ans << endl;
}
