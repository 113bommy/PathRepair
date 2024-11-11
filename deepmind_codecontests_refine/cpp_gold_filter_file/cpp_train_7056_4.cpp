#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;

int main(){
  string s;
  cin >> s;
  int q;
  cin >> q;
  string t;
  rep(qi,q){
    int ty;
    cin >> ty;
    if (ty==1){
      swap(s,t);
    }
    else {
      int f;
      char c;
      cin >> f >> c;
      if (f==1){
        t+=c;
      }
      else {
        s+=c;
      }
    }
  }
  reverse(t.begin(),t.end());
  t+=s;
  cout << t << endl;
  return 0;
}
