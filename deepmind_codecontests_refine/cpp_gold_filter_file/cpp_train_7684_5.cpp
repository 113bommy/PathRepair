#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,h=0;cin>>a>>b;
  for(int i=1;i<b-a;i++)h+=i;
  cout<<h-a<<endl;
}
