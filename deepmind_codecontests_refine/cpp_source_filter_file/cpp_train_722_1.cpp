#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int a[50],b[50],n;
  cin>>n;
    double c=0,d=0;
    r(i,n){
      cin>>a[i]>>b[i];
      c+=a[i],d+=b[i];
    }
    c/=n,d/=n;
    if(n%2)goto L;
    r(i,n/2)if(!abs((a[i]+a[(i+n/2)%n])/2-c)<=0.0001||!abs((b[i]+b[(i+n/2)%n])/2-c))<=0.0001)goto L;
    printf("%.11f %.11f\n",c,d);
    if(0)L:cout<<"NA"<<endl;
}