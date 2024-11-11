#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
string s;
vector<int> openPos, closePos;
long long getVal(int sIdx, int eIdx) {
  if (eIdx < sIdx) return 0;
  long long ret = 0;
  long long add = 1;
  for (int i = sIdx; i < (int)eIdx + 1; i++) {
    if (s[i] != '*' && s[i] != '+') {
      add *= s[i] - '0';
      if (i == eIdx || s[i + 1] == '+') {
        ret += add;
        add = 1;
      }
    }
  }
  return ret;
}
int main() {
  cin >> s;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == '*') {
      bool b = false, b1 = false;
      if (i >= 3) {
        if (s[i - 2] == '+') b1 = true;
      }
      if (i < s.length() - 3) {
        if (s[i + 2] == '+') b = true;
      }
      if (b) openPos.push_back(i);
      if (b1) closePos.push_back(i);
    }
  }
  openPos.push_back(-1);
  closePos.push_back(s.length());
  long long ret = getVal(0, s.length() - 1);
  for (int i = 0; i < (int)openPos.size(); i++) {
    int pos1 = openPos[i];
    for (int j = 0; j < (int)closePos.size(); j++) {
      int pos2 = closePos[j];
      if (pos1 + 3 < pos2) {
        int pos0 = pos1, pos3 = pos2;
        long long tmp = 1;
        while (pos0 > -1) {
          pos0 -= 2;
          tmp *= s[pos0 + 1] - '0';
          if (pos0 == -1 || s[pos0] == '+') break;
        }
        while (pos3 < s.length()) {
          pos3 += 2;
          tmp *= s[pos3 - 1] - '0';
          if (pos3 == s.length() || s[pos3] == '+') break;
        }
        long long ret1 = getVal(0, pos0 - 1) +
                         tmp * getVal(pos1 + 1, pos2 - 1) +
                         getVal(pos3 + 1, s.length() - 1);
        ret = max(ret, ret1);
      }
    }
  }
  cout << ret << endl;
  return 0;
}
