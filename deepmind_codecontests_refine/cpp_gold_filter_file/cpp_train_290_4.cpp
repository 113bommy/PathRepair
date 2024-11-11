#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,n,r=0; cin>>n;
  for(int i=0;i<n;++i){
    cin>>a;r+=a;
  }
  cout << r-n <<endl;
}
