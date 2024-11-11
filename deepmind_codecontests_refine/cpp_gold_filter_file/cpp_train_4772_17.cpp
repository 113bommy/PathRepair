#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,k;
 cin>>s>>k;
  sort(s.begin(),s.end());
  sort(k.begin(),k.end());
  reverse(k.begin(),k.end());
  
  if(s<k) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
