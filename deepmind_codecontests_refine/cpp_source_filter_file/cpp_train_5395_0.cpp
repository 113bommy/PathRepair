#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,sum=0; cin>>n;
  for(int i=1;i<n+1;i++){
    int sum2=0
    for(int j=1;j<i+1;j++){
      if(i%j==0) sum2++;
    }
    if(sum2==8 &&i%2==1) sum++
  }
  cout<<sum<<endl;
}  
