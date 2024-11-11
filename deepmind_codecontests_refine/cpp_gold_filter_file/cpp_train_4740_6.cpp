#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = (int)1e7 + 7, mod = 1000000007, M = 2e9;
struct S {
  string s;
  int a, b;
} in[12];
int n, c;
vector<string> ans;
void dtct(string s) {
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (s[i] == s[j]) return;
    }
  }
  for (int i = 0; i < n; i++) {
    int a = 0, b = 0;
    for (int j = 0; j < 4; j++) a += (s[j] == in[i].s[j]);
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) b += (s[j] == in[i].s[k]);
    }
    b -= a;
    if (in[i].a != a || in[i].b != b) return;
  }
  if (ans.size()) {
    cout << "Need more data";
    exit(0);
  }
  ans.push_back(s);
}
void gen(string s = "") {
  if (s.size() == 4)
    dtct(s);
  else {
    for (char i = '0'; i <= '9'; i++) gen(s + i);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> in[i].s >> in[i].a >> in[i].b;
  gen();
  if (ans.size())
    cout << ans[0];
  else
    cout << "Incorrect data";
  return 0;
}
