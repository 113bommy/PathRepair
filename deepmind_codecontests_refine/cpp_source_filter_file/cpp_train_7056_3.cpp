#include <bits/stdc++.h>
using namespace std;

string s;
int q, t, f;
char c;
int main(){
  string pre, suf;
  bool back = false;
  cin >> s >> q;
  while (q--) {
    cin >> t;
    if (t==1) {
      back = !back;
      swap(pre, suf);
    } else {
      cin >> f >> c;
      if (f==1) pre += c;
      else suf += c;
    }
  }
  reverse(pre.begin(), pre.end());
  if (back) back(s.begin(), s.end());
  cout << pre << s << suf << endl;
}
