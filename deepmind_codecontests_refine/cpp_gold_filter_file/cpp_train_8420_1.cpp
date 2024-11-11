#include <iostream>
#include <math.h>
#define S(n) (int)(pow(3,x-(n)+1)/2)
using namespace std;

int main(){
	int h[17],a[17],c[17],x,i,n,m,t;
	while(cin>>x>>n,n){
		for(i=0;i<3;i++)for(cin>>m;m--;h[t]=i)cin>>t;
		a[x]=h[x];c[x]=2-h[x];
		for(i=x;i>1;i--){
			if(h[i-1]==0){
				a[i-1]=a[i];
				c[i-1]=c[i]+2+4*S(i);
			}else if(h[i-1]==1){
				a[i-1]=c[i]+1+2*S(i);
				c[i-1]=a[i]+1+2*S(i);
			}else{
				a[i-1]=a[i]+2+4*S(i);
				c[i-1]=c[i];
			}
		}
		t=min(a[1],c[1]);
		cout<<(t>n?-1:t)<<endl;
	}
}