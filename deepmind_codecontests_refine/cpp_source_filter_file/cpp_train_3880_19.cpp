#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int digit[N], d1[N], d2[N];
int main() {
  string num;
  while (cin >> num) {
    memset(digit, 0, sizeof(digit));
    for (int i = 0; i < num.size(); i++) digit[num[i] - '0']++;
    int d = -1, len = 0;
    for (int i = 1; i <= 9; i++) {
      if (digit[i] == 0 || digit[10 - i] == 0) continue;
      memcpy(d1, digit, sizeof(d1));
      memcpy(d2, digit, sizeof(d2));
      d1[i]--;
      d2[10 - i]--;
      int ans = 0;
      for (int j = 0; j <= 9; j++) ans += min(d1[j], d2[9 - j]);
      if (ans > len) {
        len = ans;
        d = i;
      }
    }
    if (d == -1) {
      string out, add;
      for (int j = 0; j < digit[0]; j++) out += '0';
      for (int i = 1; i <= 9; i++)
        for (int j = 0; j < digit[i]; j++) add += char(i + '0');
      cout << add + out << endl;
      cout << add + out << endl;
      continue;
    }
    string n1, n2;
    memcpy(d1, digit, sizeof(d1));
    memcpy(d2, digit, sizeof(d2));
    d1[d]--;
    d2[10 - d]--;
    n1 += char(d + '0');
    n2 += char(10 - d + '0');
    for (int i = 0; i <= 9; i++) {
      int lim = min(d1[i], d2[9 - i]);
      string add1, add2;
      for (int j = 0; j < lim; j++) {
        add1 += char(i + '0');
        add2 += char(9 - i + '0');
        d1[i]--;
        d2[9 - i]--;
      }
      n1 = add1 + n1;
      n2 = add2 + n2;
    }
    int lim = min(d1[0], d2[0]);
    for (int i = 0; i < lim; i++) {
      n1 += '0';
      n2 += '0';
    }
    d1[0] -= lim;
    d2[0] -= lim;
    string add1, add2;
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j < d1[i]; j++) {
        add1 += char(i + '0');
      }
      for (int j = 0; j < d2[i]; j++) {
        add2 += char(i + '0');
      }
    }
    n1 = add1 + n1;
    n2 = add2 + n2;
    cout << n1 << endl;
    cout << n2 << endl;
  }
  return 0;
}
