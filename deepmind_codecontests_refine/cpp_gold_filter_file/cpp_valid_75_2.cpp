#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
vector<long long> prime;
bool num[1000005 + 2];
void sieve() {
  num[0] = true;
  num[1] = true;
  for (long long i = 2; i <= 1000005; i++) {
    if (num[i] == false) {
      prime.push_back(i);
      for (long long j = 2 * i; j <= 1000005; j = j + i) {
        num[j] = true;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, j, k, l, a, b, c, p, q, r, t, ans, sum;
  cin >> t;
  vector<pair<long long, long long> > v;
  while (t--) {
    cin >> n;
    m = n;
    j = 0;
    while (n--) {
      cin >> k >> a;
      b = a + 1;
      c = b + 1;
      for (i = 1; i < k; i++) {
        cin >> a;
        if (a >= c) {
          b = b + (a - c) + 1;
          c = a + 2;
        } else
          c++;
      }
      v.push_back(make_pair(b, k));
    }
    sort(v.begin(), v.end());
    b = v[0].first + v[0].second;
    a = v[0].first;
    for (i = 1; i < m; i++) {
      if (v[i].first > b) {
        c = v[i].first - b;
        b = v[i].first + v[i].second;
        a = a + c;
      } else {
        b = b + v[i].second;
      }
    }
    cout << a << endl;
    v.clear();
  }
  return 0;
}
