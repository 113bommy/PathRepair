#include <iostream>
using namespace std;
int main(){int n,c,t,f,i;for(;;){cin>>n;if(!n){break;}c=0;t=0;f=0;for(i=1;i<=n;i++){int m=i;while(m%2==0){t++;m/=2;}m=i;while(m%5==0){f++;m/=5;}}cout<<t<f?t:f<<endl;}return 0;}