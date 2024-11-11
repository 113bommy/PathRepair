#include <bits/stdc++.h>
using namespace std;
long long pow10_mod(int e) {
  long long base = 10, ans = 1;
  while (e) {
    if (e & 1) ans = (ans * base) % 1000000007;
    base = (base * base) % 1000000007;
    e >>= 1;
  }
  return ans;
}
char s[100001];
int main() {
  int n;
  scanf("%s %d\n", s, &n);
  string t(s);
  stack<pair<char, string> > rules;
  rules.push({'9' + 1, t});
  for (int i = 0; i < n; i++) {
    char d;
    scanf("%c->", &d);
    cin.getline(s, 100001);
    string t(s);
    rules.push({d, t});
  }
  int digs[11], rem[11];
  for (int i = 0; i < 10; i++) {
    digs[i] = 1;
    rem[i] = i;
  }
  while (!rules.empty()) {
    auto p = rules.top();
    rules.pop();
    int c = p.first - '0';
    string t = p.second;
    int r = 0, cnt = 0;
    for (char tt : t) {
      r = (int)((r * pow10_mod(digs[tt - '0']) + rem[tt - '0']) % 1000000007);
      cnt = (cnt + digs[tt - '0']) % (1000000007 - 1);
    }
    rem[c] = r;
    digs[c] = cnt;
  }
  cout << rem[10] << endl;
  return 0;
}
