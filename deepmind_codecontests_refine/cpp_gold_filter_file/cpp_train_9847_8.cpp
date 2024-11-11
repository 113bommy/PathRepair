#include <bits/stdc++.h>
using namespace std;
struct express {
  int op1;
  int op2;
  string op;
  string res;
  bool flag;
};
map<string, int> mmap;
int n, m;
express h[5050];
string v[5050];
char ans0[1010], ans1[1010];
string toInt(string operand) {
  for (int i = 0; i < operand.length(); i++) operand[i] -= '0';
  return operand;
}
int compute(int b1, int b2, string op) {
  int res = 0;
  if (op[0] == 'A')
    res = b1 & b2;
  else if (op[0] == 'O')
    res = b1 | b2;
  else
    res = b1 ^ b2;
  return res;
}
int cnt(int bit, int i) {
  int t = 0, res;
  h[0].res[i] = bit;
  for (int k = 1; k <= n; k++) {
    if (h[k].flag) continue;
    res = compute(h[h[k].op1].res[i], h[h[k].op2].res[i], h[k].op);
    h[k].res[i] = res;
    if (res) t++;
  }
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) h[i].res.resize(m);
  memset(ans0, 0, sizeof(ans0));
  memset(ans1, 0, sizeof(ans1));
  string assign, op1, op, op2;
  bool flag = true;
  mmap["?"] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> assign >> op1;
    if (op1[0] == '0' || op1[0] == '1') {
      h[i].res = toInt(op1);
      h[i].flag = true;
      mmap[v[i]] = i;
    } else {
      h[i].flag = false;
      cin >> h[i].op >> op2;
      h[i].op1 = mmap[op1];
      h[i].op2 = mmap[op2];
      mmap[v[i]] = i;
    }
  }
  for (int i = 0; i < m; i++) {
    int t0 = cnt(0, i);
    int t1 = cnt(1, i);
    if (t0 < t1) {
      ans0[i] = '0';
      ans1[i] = '1';
    } else if (t0 == t1) {
      ans0[i] = ans1[i] = '0';
    } else {
      ans0[i] = '1';
      ans1[i] = '0';
    }
  }
  cout << ans0 << endl << ans1 << endl;
}
