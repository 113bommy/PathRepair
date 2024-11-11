#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
void def(string a, string b) {
  int cnt = 0;
  string str;
  for (auto &ch : a) {
    if (ch == '&')
      --cnt;
    else if (ch == '*')
      ++cnt;
    else
      str += ch;
  }
  a = str;
  if (!mp.count(a)) {
    mp[b] = -1;
  } else if (mp[a] < 0) {
    mp[b] = -1;
  } else {
    mp[b] = mp[a] + cnt;
  }
}
string get(string a) {
  int cnt = 0;
  string str;
  for (auto &ch : a) {
    if (ch == '&')
      --cnt;
    else if (ch == '*')
      ++cnt;
    else
      str += ch;
  }
  a = str;
  if (!mp.count(a)) return "errtype";
  string ans = "void";
  int c = mp[a] + cnt;
  if (c - cnt < 0) return "errtype";
  for (int i = 0; i < c; i++) ans += "*";
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mp["void"] = 0;
  mp["errtype"] = -1;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string op;
    cin >> op;
    if (op == "typedef") {
      string a, b;
      cin >> a >> b;
      def(a, b);
    } else {
      string a;
      cin >> a;
      cout << get(a) << "\n";
    }
  }
}
