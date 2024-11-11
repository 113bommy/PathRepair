#include<bits/stdc++.h>
using namespace std;
int main() {
  int N; cin>>N;
  int a=0,b=0,c=0,d=0;
  int ans=0;
  string s;
  for(int i=0;i<N;i++){
    cin>>s;
    if(s.at(s.size()-1)=='A') a++;
    if(s.at(0)=='B') b++;
    if(s.at(s.size()-1)=='A' && s.at(0)=='B') c++;
    for(int j=0;j<s.size()-1;j++)
      if(s.at(j)=='A' && s.at(j+1)=='B') d++;
  }
  a-=c;b-=c;
  if(a==0&&b==0&&c!=0) ans=c+d-1;
  else if(a==0&&b==0&&c==0) ans=d;
  else if((a!=0&&b==0) or (a==0&&b!=0)) ans=c+d;
  else ans=c+d+min(a,b);
  cout<<ans<<endl;
}
