#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
for(int i=0;i<a;i++){
      if(i)cout<<' ';
      if(i<=a/2)cout<<0;
      else cout<<b;
}cout<<endl;
}