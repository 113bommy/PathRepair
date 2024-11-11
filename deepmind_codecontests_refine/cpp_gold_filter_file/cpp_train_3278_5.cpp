#include <bits/stdc++.h>
using namespace std;
string t;
string tos(int i, int j, int k) {
  string ans = "";
  if (i != -1) ans += t[i];
  if (j != -1) ans += t[j];
  if (k != -1) ans += t[k];
  return ans;
}
int _stoi(string st) {
  int sum = 0;
  for (int i = 0; i < st.size(); ++i) sum *= 10, sum += st[i] - '0';
  return sum;
}
bool ok(string st) {
  if (st == "") return false;
  int a = _stoi(st);
  if (a % 8 == 0 && (!a || a % 10)) return 1;
  return false;
}
int main() {
  while (getline(cin, t)) {
    string ANS = "";
    int sz = t.size();
    bool flag = 1;
    for (int i = 0; i < sz; ++i) {
      if (flag && ok(tos(i, -1, -1))) {
        ANS = tos(i, -1, -1);
        flag = 0;
      }
      for (int j = i + 1; j < sz; ++j) {
        if (flag && ok(tos(i, j, -1))) {
          ANS = tos(i, j, -1);
          flag = 0;
        }
        for (int k = j + 1; k < sz; ++k) {
          if (flag && ok(tos(i, j, k))) {
            ANS = tos(i, j, k);
            flag = 0;
          }
        }
      }
    }
    cout << (flag ? "NO" : "YES") << endl;
    if (!flag) cout << ANS << endl;
  }
  return 0;
}
