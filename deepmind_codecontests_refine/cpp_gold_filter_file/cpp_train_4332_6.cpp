#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long PO(long long a, long long n) {
  long long val = 1;
  for (long long i = 0; i < n; i++) val *= a;
  return val;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
char s[1000100], t[1000100];
int n1, n2;
int fs[200] = {0};
signed main() {
  int cnt = 0;
  cin >> s >> t;
  vector<char> x;
  n1 = strlen(s);
  n2 = strlen(t);
  if (n1 < n2) {
    for (long long i = 0; i < n1; i++) cout << s[i];
    return 0;
  }
  for (auto it : s) {
    if (it != '?')
      fs[it]++;
    else
      cnt++;
  }
  for (int i = 0; i < n2; i = (i + 1) % n2) {
    if (cnt == 0) break;
    char req = t[i];
    if (fs[req] > 0) {
      fs[req]--;
    } else {
      if (cnt > 0) {
        x.push_back(req);
        cnt--;
      }
    }
  }
  int off = 0;
  for (int i = 0; i < n1; i++) {
    if (s[i] == '?') {
      cout << x[off];
      off++;
      continue;
    }
    cout << s[i];
  }
}
