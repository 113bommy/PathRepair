#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,c,a=0;cin>>n>>m>>c;
  vector<int>b(m);for(int i=0;i<m;i++)cin>>b.at(i);
  for(int i=0;i<n;i++){
    int x=c;
    for(int j=0;j<m;j++){int y;cin>>y;x+=b.at(j)*y;}
    if(x>0)a++;
  }
  cout<<a<<endl;
}
