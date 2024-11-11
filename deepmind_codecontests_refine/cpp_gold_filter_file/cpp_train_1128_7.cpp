#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c,r=0;
  cin>>n;
  map<int,int> m;
  for(int i=0;i<n;++i){
    cin>>c;
    if((c/=400)>=8)r++;
    else m[c]++;
  }
  cout<<max((int)m.size(),1)<<" "<<m.size()+r<<endl;
  return 0;
}