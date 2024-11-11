#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  int mi=1001;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    mi=min(mi,a);
    x-=a;
  }
  cout<<n+(x/mi);
}
