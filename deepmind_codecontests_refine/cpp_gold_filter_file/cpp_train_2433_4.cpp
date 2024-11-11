#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> q;
vector<long long> apply_q(vector<long long> v) {
  vector<long long> res(n);
  for (long long i = 0; i < n; i++) {
    res[i] = v[q[i]];
  }
  return res;
}
vector<long long> inverse_q(vector<long long> v) {
  vector<long long> res(n);
  for (long long i = 0; i < n; i++) {
    res[q[i]] = v[i];
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long k;
  cin >> n >> k;
  q.resize(n);
  vector<long long> s(n);
  vector<long long> og(n);
  for (long long i = 0; i < n; i++) {
    cin >> q[i];
    q[i]--;
    og[i] = i;
  }
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    s[i]--;
  }
  bool ch = 0;
  if (og == s) {
    cout << "NO";
    return 0;
  }
  for (long long i = 0; i < k; i++) {
    og = apply_q(og);
    if (og == s) {
      if (i < k - 1) {
        if (i == 0) {
          for (long long j = 0; j < n; j++) {
            og[j] = j;
          }
          if (inverse_q(og) == s)
            ;
          else if ((k - 1 - i) % 2 == 0)
            ch = 1;
        } else {
          if ((k - 1 - i) % 2 == 0) ch = 1;
        }
      } else
        ch = 1;
      break;
    }
  }
  for (long long i = 0; i < n; i++) {
    og[i] = i;
  }
  for (long long i = 0; i < k; i++) {
    og = inverse_q(og);
    if (og == s) {
      if (i < k - 1) {
        if (i == 0) {
          for (long long j = 0; j < n; j++) {
            og[j] = j;
          }
          if (apply_q(og) == s)
            ;
          else if ((k - 1 - i) % 2 == 0)
            ch = 1;
        } else {
          if ((k - 1 - i) % 2 == 0) ch = 1;
        }
      } else
        ch = 1;
      break;
    }
  }
  if (ch)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
