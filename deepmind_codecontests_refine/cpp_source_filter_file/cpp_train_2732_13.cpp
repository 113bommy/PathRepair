#include <bits/stdc++.h>
using namespace std;
long long hide;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
const int N = 1e5 + 5;
int p[N], tot;
bool tag[N];
void prime(int n) {
  int i, j;
  for (i = 2; i <= n; i++) {
    if (!tag[i]) p[++tot] = i;
    for (j = 1; j <= tot && i * p[j] <= n; j++) {
      tag[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
void divide(long long x, vector<pair<long long, long long> >& v) {
  v.clear();
  for (int i = 1; i <= tot && x > 1; i++) {
    if (x % p[i] == 0) {
      v.push_back(pair<long long, long long>(p[i], 0));
      while (x % p[i] == 0) {
        v[v.size() - 1].second++;
        x /= p[i];
      }
    }
  }
  if (x > 1) v.push_back(pair<long long, long long>(x, 1));
}
long long ans;
int times;
void query(long long x);
long long cur = 1;
void insert(long long pr, int limit) {
  if (times >= 22) return;
  long long x = 1, cnt = 1;
  while (x <= 1.5e9 / ans / pr && cnt <= limit) x *= pr, cnt++;
  if (cur <= 0.999e18 / x)
    cur *= x;
  else {
    swap(cur, x);
    query(x);
  }
}
void query(long long x) {
  if (times >= 22) return;
  times++;
  cout << "? " << x << endl;
  cout.flush();
  long long ret;
  cin >> ret;
  vector<pair<long long, long long> > v, vx;
  divide(x, vx);
  divide(ret, v);
  for (int i = 0, k = 0; i < (int)v.size(); i++) {
    while (vx[k].first < v[i].first) k++;
    if (vx[k].second == v[i].second) {
      insert(v[i].first, v[i].second * 6);
      continue;
    }
    for (int j = 1; j <= v[i].second; j++) ans *= v[i].first;
  }
}
long long calc(long long ans) {
  vector<pair<long long, long long> > v;
  divide(ans, v);
  long long cnt = 1;
  for (int i = 0; i < (int)v.size(); i++) cnt *= (v[i].second + 1);
  return cnt;
}
vector<pair<long long, long long> > v;
int T;
int main() {
  prime(N - 1);
  cin >> T;
  while (T--) {
    ans = 1, times = 0;
    cur = 1;
    for (int pcnt = 1; pcnt <= tot && times < 22; pcnt++) insert(p[pcnt], 1);
    cout << "! " << (int)(1.5 * calc(ans)) << endl;
    cout.flush();
  }
  return 0;
}
