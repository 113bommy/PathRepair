#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long fastpower(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return fastpower((x * x) % M, n / 2, M);
  else
    return (x * fastpower((x * x) % M, (n - 1) / 2, M)) % M;
}
long long negativepow(long long base, long long expo, long long m) {
  if (m == 1) return 0;
  long long ans = 1, y = base % m;
  while (expo > 0) {
    if (expo & 1) ans = ((ans)*y) % m;
    y = (y * y) % m;
    if (y < 0) y += m;
    expo = expo >> 1;
  }
  if (ans < 0) {
    ans = (m - abs(ans) % m);
    return ans;
  }
  return ans % m;
}
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
long long modInverse(long long A, long long M) {
  return fastpower(A, M - 2, M);
}
void sieve(long long N) {
  bool isPrime[N + 1];
  for (long long i = 0; i <= N; ++i) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (long long i = 2; i * i <= N; ++i) {
    if (isPrime[i] == true) {
      for (long long j = i * i; j <= N; j += i) isPrime[j] = false;
    }
  }
}
bool isPrime(long long n) {
  if (n <= 1) return 0;
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n % 3 == 0)
    return 0;
  else {
    for (long long i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
  }
}
map<long long, long long> factor(long long n) {
  map<long long, long long> pm;
  long long i;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        pm[i]++;
        n = n / i;
      }
    }
  }
  if (n > 1) pm[n]++;
  return pm;
}
void printDivisors(long long n) {
  vector<long long> v;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void print(vector<long long> v) {
  for (auto it : v) cout << it << " ";
  cout << "\n";
}
long long count_one(long long n) {
  long long count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}
long long sz(string s) { return s.length(); }
vector<long long> v[205];
long long color[205];
bool flag;
bool check(long long n) {
  flag = true;
  for (long long i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = 0;
      queue<long long> q;
      q.push(i);
      while (!q.empty()) {
        long long x = q.front();
        q.pop();
        for (auto xx : v[x]) {
          if (color[xx] == -1) {
            color[xx] = 1 ^ color[x];
            q.push(xx);
          } else {
            flag &= color[xx] != color[x];
          }
        }
      }
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  memset(color, -1, sizeof(color));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      if (s[j] > s[i]) {
        v[j].push_back(i);
        v[i].push_back(j);
      }
    }
  }
  if (check(n)) {
    cout << "YES\n";
    for (long long i = 0; i < n; i++) cout << color[i];
  } else
    cout << "NO\n";
  return 0;
}
