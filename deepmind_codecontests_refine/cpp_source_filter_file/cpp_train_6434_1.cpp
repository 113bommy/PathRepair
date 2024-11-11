#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  int h=0;
  int g=1000000000;
  for(int i=0;i<m;i++){
    int a,s;
    cin>>a>>s;
    h=max(h,a);
    g=mix(g,s);
  }
  if(h>g){
    cout<<0<<endl;
  }
  else{
    cout<<g-h+1<<endl;
  }
}
