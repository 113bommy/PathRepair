#include<bits/stc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  if (s.back() == 's') s += "es";
  else s += "s";
  cout << s << endl;
}