#include <iostream>
#include <cmath>
using namespace std;
#define Rep(i,n) for(int i=0;i<(n);i++)
int a[50];
int b[50];
int c[50];
int d[50];
int main(void)
{
int N,M;
cin>>N>>M;
Rep(i,N)cin>>a[i]>>b[i];
Rep(i,M)cin>>c[i]>>d[i];
Rep(n,N){
 int ans=1;
 int mn=abs(a[n]-c[0])+abs(b[n]-d[0]);
 Rep(m,M){
  if(abs(a[n]-c[m])+abs(b[n]-d[m])<mn){
   mn=abs(a[n]-c[m])+abs(b[n]-d[m]);
   ans=m+1
  }
 }
 cout<<ans<<endl;
}
return 0;
}