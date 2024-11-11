#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e=-100,f= 100,g;
  cin>>a>>b>>c>>d;
  for(int i=0;i<a;i++){
    cin>>g;
    e=max(e,g);
  }
  for(int i=0;i<b;i++){
    cin>>g;
    f=min(f,g);
  }
  for(int i=c+1;i<=d;i++){
    if(e<i&&i<=f){
      cout<<"No War"<<endl;
      break;
    }
    if(i==d)
      cout<<"War"<<endl;
  }
}