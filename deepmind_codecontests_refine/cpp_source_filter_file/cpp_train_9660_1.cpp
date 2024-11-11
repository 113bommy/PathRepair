#include <iostream>
using namespace std;
char p;
int l, lp;
long long r;
int main() {
  ios_baase::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  for(char c: s) {
    if(c != p) {
      if(c == '<')
        r -= l < lp ? l : lp;
      p = c; lp = l; l = 0;
    }
    r += ++l;
  }
  if(p == '>')
    r -= l < lp ? l : lp;
  cout << r << '\n';
  return 0;
}
