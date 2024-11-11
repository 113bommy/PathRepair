#include <bits/stdc++.h>
using namespace std;
struct incre {
  bool add_first;
  int coef;
  incre() { add_first = coef = 0; }
  incre(bool add_first, int coef) : add_first(add_first), coef(coef) {}
};
vector<incre> vec;
bool operator<(const incre &_1, const incre &_2) { return _1.coef < _2.coef; }
string str;
bool vis[1000000];
bool isNum(char c) { return c >= '0' && c <= '9'; }
incre Get(int i) {
  bool add_first;
  add_first = (i >= 2 && str[i - 1] == '+' && str[i - 2] == '+' &&
               !vis[i - 1] && !vis[i - 2]);
  if (add_first) i -= 2;
  vis[i + 1] = vis[i + 2] = true;
  if (i == 0) return incre(add_first, 1);
  --i;
  if (str[i] == '+') return incre(add_first, 1);
  if (str[i] == '-') return incre(add_first, -1);
  int coef = 0, pow10 = 1;
  while (--i >= 0 && isNum(str[i])) {
    coef += (str[i] - '0') * pow10;
    pow10 *= 10;
  }
  if (i >= 0 && str[i] == '-') coef *= -1;
  return incre(add_first, coef);
}
void get_incre() {
  for (int i = 0; i < str.size(); i++)
    if (str[i] == 'a') vec.push_back(Get(i));
  return;
}
int main() {
  int a, res = 0;
  cin >> a >> str;
  get_incre();
  sort(vec.begin(), vec.end());
  for (vector<incre>::iterator it = vec.begin(); it != vec.end(); it++)
    res += (it->add_first ? ++a : a++) * (it->coef);
  cout << res << '\n';
  return 0;
}
