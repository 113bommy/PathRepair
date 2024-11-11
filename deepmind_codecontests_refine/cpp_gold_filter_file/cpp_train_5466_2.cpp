#include <bits/stdc++.h>
using namespace std;
int n, l;
bool def;
int mf[11000];
vector<string> v;
bool lessthan(const string a, const string b) {
  int t;
  if (a.length() > b.length())
    t = a.compare(0, b.length(), b);
  else
    t = -b.compare(0, a.length(), a);
  if (t != 0) return t < 0;
  return def ^ (b.length() > a.length());
}
int main() {
  cin >> n;
  string s;
  s = "aa";
  for (int i = 0; i < n; i++) {
    cin >> s;
    l += s.length();
    v.push_back(s);
  }
  l /= (n / 2);
  cin >> s;
  def = s[0] > 'b';
  sort(v.begin(), v.end(), &lessthan);
  for (int i = 0; i < v.size(); i++)
    if (!mf[i]) {
      mf[i] = true;
      for (int k = i + 1; k < v.size(); k++)
        if (!mf[k])
          if (v[i].length() + v[k].length() == l) {
            mf[k] = true;
            cout << v[i] << s[0] << v[k] << endl;
            break;
          }
    }
  return 0;
}
