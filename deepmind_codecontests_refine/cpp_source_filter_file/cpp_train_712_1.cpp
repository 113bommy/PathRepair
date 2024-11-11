#include<bits/stdc++.h>
using namespace std;
int main(){
  double a,b,c;
  while(cin>>a>>b>>c){
    int sum=0;
    a=a%b*10;
    while(c--){
      sum+=a/b;
      a=a%b*10;
    }
    cout<<sum<<endl;
  }
}