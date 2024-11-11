#include <bits/stdc++.h>
using namespace std;
class BigNum {
 public:
  string num;
  BigNum() {}
  BigNum(string str) {
    num = str;
    simplify();
  }
  bool operator!=(BigNum t) { return num != t.num; }
  bool operator==(BigNum t) { return num == t.num; }
  bool operator<(BigNum t) {
    if (num.size() != t.num.size()) {
      return num.size() < t.num.size();
    }
    for (int i = num.size(); i >= 0; i--) {
      if (num[i] != t.num[i]) return num[i] < t.num[i];
    }
    return false;
  }
  bool operator<=(BigNum t) { return *this < t || *this == t; }
  void simplify() {
    int t = 0;
    for (int i = 0; i < num.size(); i++) {
      num[i] += t;
      if (num[i] > '9') {
        t = ((num[i] - '0') / 10);
        num[i] = ((num[i] - '0') % 10) + '0';
      } else if (num[i] < '0') {
        t = (num[i] - '0' - 9) / 10;
        num[i] = ((num[i] - '0') + 100) % 10 + '0';
      } else {
        t = 0;
      }
    }
    while (t) {
      num.push_back(t % 10 + '0');
      t /= 10;
    }
    int i = num.size() - 1;
    while (num[i] == '0') i--;
    num.erase(i + 1, num.size());
    if (!num.size()) num.push_back('0');
  }
  BigNum operator+(BigNum t) {
    BigNum t2(num);
    while (t2.num.size() < t.num.size()) t2.num.push_back('0');
    for (int i = 0; i < t.num.size(); i++) t2.num[i] += t.num[i] - '0';
    t2.simplify();
    return t2;
  }
  BigNum operator+(long long t) {
    BigNum t2;
    t2 = t;
    return *this + t2;
  }
  BigNum operator-(BigNum t) {
    BigNum t2(num);
    for (int i = 0; i < t.num.size(); i++) {
      t2.num[i] = t2.num[i] - t.num[i] + '0';
    }
    t2.simplify();
    return t2;
  }
  BigNum operator-(long long t) {
    BigNum t2;
    t2 = t;
    return *this - t2;
  }
  BigNum operator=(long long t) {
    num.clear();
    while (t) {
      num.push_back(t % 10 + '0');
      t /= 10;
    }
    simplify();
    return *this;
  }
  BigNum operator*(long long t) {
    long long k = 0;
    BigNum t2(num);
    for (int i = 0; i < t2.num.size(); i++) {
      long long d = ((t2.num[i] - '0') * t + k);
      t2.num[i] = d % 10 + '0';
      k = d / 10;
    }
    while (k) {
      t2.num.push_back(k % 10 + '0');
      k /= 10;
    }
    t2.simplify();
    return t2;
  }
  BigNum operator*(BigNum t) {
    BigNum bs, tmpd[10], res, tmp;
    int l2 = t.num.size();
    int i;
    tmpd[0] = 0;
    for (i = 1; i < 10; i++) {
      tmpd[i] = tmpd[i - 1];
      tmpd[i] = tmpd[i] + *this;
    }
    res = 0;
    for (i = 0; i < l2; i++) {
      tmp = bs;
      bs.num.push_back('0');
      tmp.num += tmpd[t.num[i] - '0'].num;
      res = res + tmp;
    }
    return res;
  }
  BigNum operator/(long long t) {
    BigNum t2(num);
    long long c = 0, d;
    for (int i = t2.num.size() - 1; i >= 0; i--) {
      d = c * 10 + (t2.num[i] - '0');
      c = d % t;
      d /= t;
      t2.num[i] = d + '0';
    }
    int i = t2.num.size() - 1;
    while (t2.num[i] == '0') i--;
    t2.num.erase(i + 1, t2.num.size());
    t2.simplify();
    return t2;
  }
  BigNum operator%(long long t) {
    long long c = 0, d;
    for (int i = num.size() - 1; i >= 0; i--) {
      d = c * 10 + (num[i] - '0');
      c = d % t;
      d /= t;
    }
    BigNum t2;
    t2 = c;
    return t2;
  }
  void input() {
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    num = str;
    simplify();
  }
  void print() {
    for (int i = num.size() - 1; i >= 0; i--) cout << num[i];
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int aa;
  BigNum a;
  BigNum x;
  cin >> aa;
  a = aa;
  BigNum i45, i19, ie18, i1, ie19;
  i45 = 45;
  i19 = 19;
  ie18 = (long long)1e18;
  ie19 = ie18 * 10;
  i1 = 1;
  x = (i45 * i19);
  x = x * ie18;
  x = x % aa;
  x = x + i1;
  x = x % aa;
  BigNum ans1, ans2;
  ans1 = a - x;
  ans1 = ans1 + i1;
  ans2 = a - x;
  ans2 = ans2 + ie19;
  ans1.print();
  cout << " ";
  ans2.print();
}
