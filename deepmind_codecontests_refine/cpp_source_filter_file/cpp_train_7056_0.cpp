#include <bits/stdc++.h>
using namespace std;
int main() {
  string _s; int n;
  cin>>skipws>>_s>>n;
  deque<char> s(_s.begin(),_s.end());
  bool f=false;
  for (int i=0;i<n;i++){
    int t;cin>>t;
    if (t==1){
      f^=1;
    }else{
      int s;char c;
      cin>>s>>c;
      if ((s==1)^f){
        s.push_front(c);
      }else{
        s.push_back(c);
      }
    }
  }
  if (f) reverse(s.begin(),s.end());
  string a(s.begin(),s.end());
  cout<<a<<endl;
}