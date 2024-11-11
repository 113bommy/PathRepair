#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
bool isprime(long long int x) {
  for (long long int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
long long int modpow(long long int x, long long int y) {
  x %= 1000000007;
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res *= x % 1000000007;
    y = y >> 1;
    x = x * x % 1000000007;
  }
  return res % 1000000007;
}
long long int ncr(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (long long int i = 0; i < (long long int)k; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long int bintodec(long long int n) {
  long long int decimal = 0, i = 0, rem;
  while (n != 0) {
    rem = n % 10;
    n /= 10;
    decimal += rem * pow(2, i);
    ++i;
  }
  return decimal;
}
void create(vector<long long int> graph[], long long int n, long long int m) {
  long long int a, b;
  while (m--) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}
void createweighted(vector<pair<long long int, long long int> > pp[],
                    long long int n, long long int m) {
  long long int a, b, wt;
  while (m--) {
    cin >> a >> b >> wt;
    pp[a].push_back(make_pair(b, wt));
    pp[b].push_back(make_pair(a, wt));
  }
}
void printweighted(vector<pair<long long int, long long int> > pp[],
                   long long int n) {
  long long int v, w;
  for (long long int i = 0; i < (long long int)n; i++) {
    cout << i;
    for (auto it = pp[i].begin(); it != pp[i].end(); it++) {
      v = it->first;
      w = it->second;
      cout << "->" << v << " :" << w;
    }
    cout << '\n';
  }
}
void print(vector<long long int> graph[], long long int n, long long int m) {
  for (long long int i = 0; i < (long long int)n; i++) {
    cout << i;
    for (auto it : graph[i]) cout << "->" << it;
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int i, k, b, aa;
  vector<long long int> a;
  long long int s = 0;
  cin >> b >> k;
  bool f = false;
  for (long long int i = 0; i < (long long int)k; i++) {
    cin >> aa;
    if (aa % 2 == 1) s++;
    a.push_back(aa);
  }
  long long int y = 2;
  if (b % 2 == 0) {
    long long int x = a[a.size() - 1];
    x % 2 == 0 ? cout << "even" : cout << "odd";
  } else {
    s % 2 == 0 ? cout << "even" : cout << "odd";
  }
  return 0;
}
