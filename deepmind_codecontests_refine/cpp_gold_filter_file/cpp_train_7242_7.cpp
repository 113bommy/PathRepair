#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX = 1e6 + 10;
long long a[MAX];
long long b[MAX];
long long ans[MAX];
long long totol[MAX];
int main() {
  long long n, k, m, sum, t, len;
  string s, d;
  while (cin >> s) {
    int flag = 1;
    ans[0] = 0;
    totol[0] = 0;
    sum = 0;
    t = 0;
    len = s.size();
    map<char, long long> p;
    for (long long i = (0); i < (len); ++i) {
      p[s[i]]++;
    }
    a[1] = p['B'];
    a[2] = p['u'] / 2;
    a[3] = p['l'];
    a[4] = p['b'];
    a[5] = p['a'] / 2;
    a[6] = p['r'];
    a[7] = p['s'];
    sort(a + 1, a + 8);
    cout << a[1] << endl;
  }
  return 0;
}
