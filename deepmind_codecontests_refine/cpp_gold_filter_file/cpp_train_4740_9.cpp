#include <bits/stdc++.h>
using namespace std;
string toostr(int n) {
  string s, z = "0";
  vector<int> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  for (int i = v.size() - 1; i > -1; i--) s += char('0' + v[i]);
  if (s.size() == 3) s = z + s;
  return s;
}
bool f(int n) {
  string s = toostr(n);
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < s.size(); j++)
      if (i != j && s[i] == s[j]) return false;
  return true;
}
bool match(string s1, string s2, int a, int b) {
  int k = 0, e = 0;
  for (int i = 0; i < s1.size(); i++)
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j]) k++;
      if (i == j && s1[i] == s2[j]) e++;
    }
  if (k < a + b) return false;
  if (e != a || k - e != b) return false;
  return true;
}
int main() {
  vector<string> v;
  for (int i = 123; i < 9877; i++)
    if (f(i)) {
      v.push_back(toostr(i));
    }
  int n, a, b;
  cin >> n;
  int mark[5100];
  string s;
  for (int i = 0; i < n; i++) {
    memset(mark, 0, sizeof mark);
    cin >> s >> a >> b;
    for (int j = 0; j < v.size(); j++)
      if (!match(s, v[j], a, b)) mark[j] = 1;
    vector<string> vv;
    for (int j = 0; j < v.size(); j++)
      if (mark[j] != 1) vv.push_back(v[j]);
    v = vv;
  }
  if (v.size() == 1)
    cout << v[0] << endl;
  else if (v.size() == 0)
    cout << "Incorrect data" << endl;
  else
    cout << "Need more data" << endl;
}
