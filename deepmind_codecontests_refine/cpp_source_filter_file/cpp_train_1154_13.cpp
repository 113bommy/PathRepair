#include <bits/stdc++.h>
int z = 1000000007;
using namespace std;
vector<bool> vec(100001, 1);
bool sortinrev(const pair<int, pair<int, int> > &a,
               const pair<int, pair<int, int> > &b) {
  return (a.first > b.first);
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
long long egcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return egcd(b, a % b);
}
double logn(double a, double base) { return log2(a) / log2(base); }
bool isprime(unsigned long long n) {
  bool b = true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      b = false;
      break;
    }
  }
  return b;
}
void sieve() {
  int n = 100001;
  for (int i = 2; i * i <= n; i++) {
    if (vec[i]) {
      for (int j = i * i; j <= n; j += i) vec[j] = false;
    }
  }
}
struct node {
  int p, cf, cb;
  node *next;
};
bool compare(double a, double b) {
  double eps = 0.000001;
  return fabs(a - b) <= eps;
}
void solve() {
  int n, m, score, cnt = 0;
  cin >> n >> m;
  int v[n], x;
  score = m;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    cnt = 0;
    x = min(v[i], score);
    v[i] -= x;
    score -= x;
    if (v[i] > 0) {
      cnt += 1;
      cnt += v[i] / m;
      if (m > v[i])
        score = m - v[i];
      else if (v[i] > m) {
        if (v[i] % m)
          score = v[i] % m;
        else
          score = m;
      } else
        score = m;
    } else if (v[i] == 0 && score == 0) {
      cnt += 1;
      score = m;
    }
    cout << cnt << ' ';
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
