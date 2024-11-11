#include <bits/stdc++.h>
using namespace std;


int main() {
  string s,t;
  cin>>s;
  int q;
  cin>>q;
  while(q--) {
    int w1,w2;
    cin>>w1;
    if(w1==1) {
      swap(s,t);
    }else {
      char c;
      cin>>w2>>c;
      if(w2==1) {
        t+=c;
      }else {
        s+=c;
      }
    }
  }
  reverse(t.begin(),t.end());
  cout<<t<<s;
  return 0;
}