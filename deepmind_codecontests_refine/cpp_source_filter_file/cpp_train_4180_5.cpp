#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200500;
const long long PHI = (long long)1e9 + 6;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x1f3f3f3f3f3f3f3f;
const long long MOD = (long long)1e9 + 7;
const long long MOD1 = (long long)1e8 + 3;
const long long MOD2 = (long long)988244353;
const long long OVER_FLOW = 0xffffffff;
long long n;
string str1, str2, str3, buf;
string tar1, tar2, tar3;
long long pos[MAXN];
string get_res(string str) {
  cout << "? " << str << endl;
  cout.flush();
  string cur;
  cin >> cur;
  return cur;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> buf;
  for (long long i = 1; i <= buf.size(); i++) {
    str1.push_back('a' + i % 26);
    str2.push_back('a' + i / 26 % 26);
    str3.push_back('a' + i / 26 / 26 % 26);
  }
  tar1 = get_res(str1), tar2 = get_res(str2), tar3 = get_res(str3);
  for (long long i = 0; i < buf.size(); i++) {
    pos[i] = tar1[i] - 'a' + (tar2[i] - 'a') * 26 + (tar3[i] - 'a') * 26 * 26;
  }
  string res(buf.size(), 'a');
  for (long long i = 0; i < buf.size(); i++) {
    res[pos[i]] = buf[i];
  }
  cout << "! " << res << endl;
  return 0;
}
