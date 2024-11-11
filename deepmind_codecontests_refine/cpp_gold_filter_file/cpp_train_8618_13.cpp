#include<bits/stdc++.h>
using namespace std;

int main(){
  long n,k;
  cin>>n>>k;
  long h[n],c=0;
  for(int i=0;i<n;i++){
     cin>>h[i];
     if(h[i]>=k)c++;
  }
  cout<<c;
}
