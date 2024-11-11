#include <bits/stdc++.h>
using namespace std;
string s[11];
int b[11], c[11];
bool check(string a) {
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (a[i] == b[j]) return false;
    }
  }
  return true;
}
int bulls(string a, string b) {
  int res = 0;
  for (int i = 0; i < 4; i++) {
    if (a[i] == b[i]) res++;
  }
  return res;
}
int cows(string a, string b) {
  int res = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i] == b[j]) {
        res++;
        break;
      }
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> b[i] >> c[i];
  }
  int ans = 0;
  string shu;
  for (int i = 123; i <= 9876; i++) {
    string t;
    stringstream ss;
    ss << i;
    ss >> t;
    if (t.size() < 4) t = "0" + t;
    if (!check(t)) {
      continue;
    }
    int f = 1;
    for (int j = 1; j <= n; j++) {
      if (bulls(s[j], t) != b[j]) {
        f = 0;
        break;
      }
      if ((cows(s[j], t) - bulls(s[j], t)) != c[j]) {
        f = 0;
        break;
      }
    }
    if (f) ans++, shu = t;
  }
  if (ans > 1)
    cout << "Need more data";
  else if (ans == 0)
    cout << "Incorrect data";
  else
    cout << shu;
}
