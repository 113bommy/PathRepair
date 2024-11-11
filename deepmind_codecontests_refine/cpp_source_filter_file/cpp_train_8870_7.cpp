#include <bits/stdc++.h>
using namespace std;
long long int pow1(long long int n, long long int p) {
  if (p == 0) return 1;
  long long int x = pow1(n, p / 2);
  x = (x * x) % 1000000007;
  if (p % 2 == 0)
    return x;
  else
    return (x * n) % 1000000007;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
bool compare(const pair<long long int, long long int> &p1,
             const pair<long long int, long long int> &p2) {
  if (p1.first < p2.first) return true;
  if (p1.first == p2.first) return p1.first < p2.second;
  return false;
}
long long int const maxn = 200007;
long long int nxt[maxn];
void seive() {
  for (long long int i = 2; i < maxn; ++i) {
    if (nxt[i] == 0) {
      nxt[i] = i;
      for (long long int j = i * i; j < maxn; j += i) {
        if (j >= maxn) {
          break;
        }
        if (nxt[j] == 0) nxt[j] = i;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  for (int ti = 0; ti < test; ti++) {
    long long int i, j, k, e, f, n, a, b, c = 0, x = 0;
    cin >> n >> a >> b >> k;
    long long int h[n];
    for (long long int i = 0; i < n; i++) cin >> h[i];
    e = a + b;
    long long int r;
    vector<pair<long long int, long long int>> v;
    for (long long int i = 0; i < n; i++) {
      r = h[i] % e;
      if (r == 0) {
        r = e;
      }
      if (r <= a) {
        f = -1;
      } else {
        r = r - a;
        long long int tr = r / a;
        if (r % a != 0) {
          tr++;
        }
        tr++;
        f = tr / 2;
      }
      v.push_back(make_pair(f, h[i]));
    }
    sort(v.begin(), v.end());
    for (long long int i = 0; i < n; i++) {
      r = v[i].second % e;
      if (r == 0) {
        r = e;
      }
      if (r <= a) {
        c++;
      } else {
        r = r - a;
        long long int tr = r / a;
        if (r % a != 0) {
          tr++;
        }
        f = tr;
        if (k >= f) {
          k = k - f;
          c++;
        } else {
          break;
        }
      }
    }
    cout << c;
    cout << "\n";
  }
  return 0;
}
