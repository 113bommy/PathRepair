#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long val[10];
long long len[10];
long long mod = 1e9 + 7;
string q[100009];
long long pow_10(long long pw) {
  if (pw == 0) return 1;
  long long hf = pow_10(pw / 2);
  long long ret = (hf * hf) % mod;
  if (pw % 2) return (ret * 10) % mod;
  return ret;
}
void proc(int d, string to) {
  long long va = 0;
  long long le = 0;
  for (int i = 0; i < to.size(); i++) {
    va = (va * pow_10(len[to[i] - '0'])) % mod;
    va = (va + val[to[i] - '0']) % mod;
    le += len[to[i] - '0'];
    le %= mod - 1;
  }
  val[d] = va;
  len[d] = le;
}
int main() {
  cin >> s;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    val[i] = i;
    len[i] = 1;
  }
  for (int it = 0; it < n; it++) {
    string qqq;
    cin >> qqq;
    q[it] = qqq;
  }
  for (int it = n - 1; it >= 0; it--) {
    int d = q[it][0] - '0';
    string to = q[it].substr(3, q[it].size() - 3);
    proc(d, to);
  }
  long long ret = 0;
  for (int i = 0; i < s.size(); i++) {
    ret = (ret * pow_10(len[s[i] - '0'])) % mod;
    ret = (ret + val[s[i] - '0']) % mod;
  }
  cout << ret << endl;
}
