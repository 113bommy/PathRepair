#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;cin>>a>>b;
  	string s;
  cin>>s;
  int e = 1;
  int seen=0;
  for(int i=0;i<a+b+1;i++){
  	if(i!=a && s[i]=='-'){e=0;break;}
    if(i==a && s[i]=='-')seen=1;
  }
  if(e==1 && seen=1)cout<<"Yes\n";
  else cout<<"No\n";
}