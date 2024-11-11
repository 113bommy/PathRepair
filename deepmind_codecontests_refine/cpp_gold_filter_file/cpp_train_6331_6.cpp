#include<bits/stdc++.h>
using namespace std;

int sum,MAX;
signed main(){
int a;cin>>a;
for(int i=0;i<a;i++){
int b;cin>>b;
sum+=b;
  MAX=max(MAX,b/2);
}
  cout<<sum-MAX<<endl;
}