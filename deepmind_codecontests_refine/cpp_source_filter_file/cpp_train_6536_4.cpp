#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int r1,r2,c1,c2;
const int maxN=1e6,M=1e9+7;
ll iv[3*maxN],f1[3*maxN],f2[3*maxN];
 
ll nck(int n,int k){
  return f1[n]*f2[k]%M*f2[n-k]%M;
}
 
int main(){
  iv[1]=1;
  for(int i=2;i<3*maxN;i++)
    	inv[i]=M-M/i*inv[M%i]%M;
  f1[0]=f2[0]=1;
  for(int i=1;i<3*maxN;i++){
    f1[i]=f1[i-1]*i%M;
    f2[i]=f2[i-1]*iv[i]%M;
  }
  cin>>r1>>c1>>r2>>c2; 
  cout<<((nck(r2+c2+2,c2+1)-nck(r1+c2+1,c2+1)-nck(r2+c1+1,c1)+nck(r1+c1,c1)%M+M)%M);
  return 0;
}