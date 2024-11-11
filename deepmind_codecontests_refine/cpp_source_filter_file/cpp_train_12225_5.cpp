#include <bits/stdc++.h>
using namespace std;
const int base = 1000000000;
vector<int> a, b;
void outputnum(vector<int> &a) {
  printf("%d", a.empty() ? 0 : a.back());
  for (int i = (int)a.size() - 2; i >= 0; --i) printf("%09d", a[i]);
}
void inputnum(string &str, vector<int> &a) {
  for (int i = (int)str.length() - 1; i >= 0; i -= 9) {
    if (i < 9)
      a.push_back(atoi(str.substr(0, i + 1).c_str()));
    else
      a.push_back(atoi(str.substr(i - 8, 9).c_str()));
  }
}
int divnumrest(vector<int> &a, int b) {
  long long current = 0, carry = 0;
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    current = a[i] + 1LL * base * carry;
    a[i] = current / b;
    carry = current - 1LL * a[i] * b;
  }
  while (!a.empty() && a.back() == 0) a.pop_back();
  return (int)carry;
}
void mulnum(vector<int> &a, vector<int> &c, int b) {
  int carry = 0;
  c.clear();
  c.assign(a.size(), 0);
  for (int i = 0; i < a.size() || carry; ++i) {
    if (i == c.size()) {
      c.push_back(0);
      a.push_back(0);
    }
    long long current = 1LL * a[i] * b + carry;
    c[i] = current % base;
    carry = current / base;
  }
  while (!a.empty() && a.back() == 0) a.pop_back();
}
int count(vector<int> &a) {
  char temp[10];
  if (a.empty()) return 0;
  sprintf(temp, "%d", a.back());
  return (a.size() - 1) * 9 + strlen(temp);
}
int main() {
  int p, x;
  cin >> p >> x;
  string str(p, '9');
  inputnum(str, a);
  bool ok = 0;
  for (int i = 4; i < 10; ++i) {
    mulnum(a, b, i);
    if (!divnumrest(b, 10 * x - 1) && count(b)) {
      ok = 1;
      break;
    }
  }
  if (ok)
    outputnum(b);
  else
    cout << "Impossible\n";
  return 0;
}
