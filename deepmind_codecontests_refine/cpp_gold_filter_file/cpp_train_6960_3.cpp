#include <iostream>
#include<math.h>
using namespace std;
int w,h,n,a,b,c,x1=0,x2,y=0,y2;
int main() {
	cin>>w>>h>>n;
	x2=w;y2=h;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(c==1)x1=max(a,x1);else
		if(c==2)x2=min(a,x2);else
		if(c==3)y=max(b,y);else
		y2=min(b,y2);
	}
	if(x2>x1&&y2>y){
	cout<<(x2-x1)*(y2-y)<<endl;
	}else cout<<0<<endl;
	return 0;
}