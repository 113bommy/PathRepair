#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,nu=1e9;
  cin>>n;
  vector<int>x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  for(int i=1;i<100;i++){
    int hu=0;
    for(int j=0;j<n;j++){
      hu+=(x[j]-i)*(x[j]-i);
    }
    nu=min(nu,hu);
  }
  cout<<nu<<endl;
}
