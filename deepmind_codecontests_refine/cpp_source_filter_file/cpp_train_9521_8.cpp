#include <bits/stdc++.h>
using namespace std;
pair<int, string> p[100010];
struct data {
  int len;
  long long mod_value;
} a[10];
int tenMod(long long x) {
  long long v = 1;
  for (int i = 35; i >= 0; i--) {
    v = v * v % 1000000007;
    if ((x >> i) & 1) {
      v = v * 10;
    }
    v %= 1000000007;
  }
  return v;
}
int main() {
  string s;
  string tmp;
  int n;
  long long m = 0;
  long long ten = 0;
  cin >> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    p[i].first = tmp[0] - '0';
    p[i].second = tmp.substr(3);
  }
  for (int i = 0; i < 10; i++) {
    a[i].len = 1;
    a[i].mod_value = i;
  }
  for (int i = n - 1; i >= 0; i--) {
    int len = p[i].second.length();
    ten = 0;
    m = 0;
    for (int j = len - 1; j > -1; j--) {
      int idx = p[i].second[j] - '0';
      m = (m + a[idx].mod_value * tenMod(ten));
      ten += a[idx].len;
      if (ten > 1000000007 - 1) ten -= 1000000007 + 1;
      m %= 1000000007;
    }
    int v = p[i].first;
    a[v].len = ten;
    a[v].mod_value = m;
  }
  ten = 0;
  m = 0;
  for (int i = s.length() - 1; i > -1; i--) {
    int idx = s[i] - '0';
    m = (m + a[idx].mod_value * tenMod(ten));
    ten += a[idx].len;
    if (ten > 1000000007 - 1) ten -= 1000000007 + 1;
    m %= 1000000007;
  }
  cout << m << endl;
  return 0;
}
