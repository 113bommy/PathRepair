#include <bits/stdc++.h>
using namespace std;
int cnt[27];
const int M = 1000000007;
int main() {
  string a;
  string b;
  cin >> a >> b;
  int n = ((int)(a).size());
  int k;
  cin >> k;
  for (int i = 0; i < n; ++i) ++cnt[a[i] - 'a'];
  for (int i = 0; i < n; ++i) --cnt[b[i] - 'a'];
  for (int i = 0; i < 26; ++i)
    if (cnt[i] != 0) {
      cout << 0 << endl;
      return 0;
    }
  string t = a + a;
  if (!strstr(t.c_str(), b.c_str())) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 0) {
    cout << (int)(a == b) << endl;
    return 0;
  }
  int cnt1 = 0;
  string c;
  for (int i = 0; i < n - 1; ++i) {
    string ta = string(b.begin(), b.begin() + i + 1);
    string tb = string(b.begin() + i + 1, b.end());
    if (tb + ta == b) {
      ++cnt1;
    } else {
      c = tb + ta;
    }
  }
  int cnt2 = 0;
  if (c != "") {
    for (int i = 0; i < n - 1; ++i) {
      string ta = string(c.begin(), c.begin() + i + 1);
      string tb = string(c.begin() + i + 1, c.end());
      cnt2 += (tb + ta == b);
    }
  }
  long long t1, t2;
  if (a == b) {
    t1 = cnt1;
    t2 = n - 1 - cnt1;
  } else {
    t1 = cnt2;
    t2 = n - 1 - cnt2;
  }
  for (int i = 0; i < k - 1; ++i) {
    long long tmp = t1;
    t1 = (t1 * cnt1 + t2 * cnt2) % M;
    t2 = (t2 * (n - 1 - cnt2) + tmp * (n - 1 - cnt1)) % M;
  }
  cout << t1 << endl;
  return 0;
}
