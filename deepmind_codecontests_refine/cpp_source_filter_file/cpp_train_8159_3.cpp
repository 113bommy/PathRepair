#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
using namespace std;
const int INF = 1000000000;
const long long LINF = 4000000000000000000LL;
const double eps = 1e-9;
void prepare() {}
string s;
void read() { cin >> s; }
const int base = 10000;
struct Big {
  vector<int> v;
  void operator*=(int x) {
    for (int i = 0; i < (int)(v).size(); i++) v[i] *= x;
    v.push_back(0);
    for (int i = 0; i + 1 < (int)(v).size(); i++) {
      v[i + 1] += v[i] / base;
      v[i] %= base;
    }
    while ((int)(v).size() > 1 && v.back() == 0) v.pop_back();
  }
  void print() {
    if (v.empty()) v.push_back(0);
    printf("%d", v.back());
    for (int i = (int)(v).size() - 2; i >= 0; i--) printf("%d", v[i]);
    printf("\n");
  }
};
void mul(Big &res, int n, int k) {
  for (int i = n - k + 1; i <= n; i++) res *= i;
}
bool solve() {
  Big res;
  res.v.push_back(1);
  set<char> se;
  int c0 = 0;
  for (int i = 0; i < (int)(s).size(); i++) {
    if (s[i] == '?')
      c0++;
    else if (isalpha(s[i]))
      se.insert(s[i]);
  }
  if (s[0] == '?') {
    res *= 9;
    c0--;
  }
  reverse((res.v).begin(), (res.v).end());
  for (int i = 0; i < c0 / 4; i++) res.v.push_back(0);
  reverse((res.v).begin(), (res.v).end());
  for (int i = 0; i < c0 % 4; i++) res *= 10;
  if (isalpha(s[0])) {
    res *= 9;
    mul(res, 9, (int)(se).size() - 1);
  } else
    mul(res, 10, (int)(se).size());
  res.print();
  return false;
}
int main() {
  prepare();
  read();
  while (solve())
    ;
  return 0;
}
