#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int n, ans[1000000], flag;
string s;
void xuly(string x, int j) {
  flag = 0;
  for (int i = 0; i < x.size(); i++) {
    if (s[i] == '(' && !flag) {
      ans[i + j] = 1;
      flag = 1;
    } else if (s[i] == '(' && flag)
      flag = 0;
  }
  flag = 0;
  for (int i = 0; i < x.size(); i++) {
    if (s[i] == ')' && !flag) {
      ans[i + j] = 1;
      flag = 1;
    } else if (s[i] == ')' && flag)
      flag = 0;
  }
}
void solve() {
  cin >> n;
  cin >> s;
  string x;
  stack<int> ktra;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      ktra.push(1);
      x += '(';
    } else {
      ktra.pop();
      x += ')';
    }
    if (ktra.empty()) {
      xuly(x, i - x.size() + 1), x = "";
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i];
}
int main() { solve(); }
