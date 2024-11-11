#include<bits/stdc++.h>
using namespace std;
int main(){
int H,W,N;
  cin>>H>>W>>N;
  int r,c;
  cin>>r>>c;
  string s,t;
  cin>>s>>t;
  bool x=true;
  int a=r
  for(int i=0;i<N;i++){
    if(s.at(i)=='U')
      a--;
    if(a<=0)x=false;
    if(t.at(i)=='D'){
    if(a<H)
      a++;
    }
     }int a1=r
  for(int i=0;i<N;i++){
    if(s.at(i)=='D')
      a1++;
    if(H<a1)x=false;
    if(t.at(i)=='U'){
    if(0<a1)
      a1--;
    }
     }int a2=c;
  for(int i=0;i<N;i++){
    
    if(s.at(i)=='R')
      a2++;
    if(W<a2)x=false;
    if(t.at(i)=='L'){
    if(0<a2)
      a2--;
    }
     }int a3=c;
  for(int i=0;i<N;i++){
    
    if(s.at(i)=='L')
      a3--;
    if(a3<=0)x=false;
    if(t.at(i)=='R'){
    if(a3<W)
      a3++;
    }
     }if(x)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
   return 0;
}