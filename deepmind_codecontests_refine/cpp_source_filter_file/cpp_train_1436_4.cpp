#include<iostream>

using namespace std;

struct d{
  string s;
  int t;
}

int main(){
  int n;
  cin>>n;
  d r[n];
  for(int i=0;i<n;i++){
    cin>>r[i].s>>r[i].t;
  }
  string l;
  cin>>l;
  bool y=false;
  long long ans=0;
  for(int i=0;i<n;i++){
  	if(y){
      ans+=r[i].t;
    }
    if(r[i].s==l){
      true;
    }
  }
  cout<<ans;
  return 0;
}
