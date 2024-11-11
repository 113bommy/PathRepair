#include<iostream>
#include<algorithm>
using namespace std;
long h,w,ans=0x7fffffffffffffff,a,b,c;
int main(){
	cin>>h>>w;
	if(h%3==0||w%3==0){cout<<0<<endl;return 0;}
	for(long i=1;i<=h/2;i++){
		a=w*i;
		b=w/2*(h-i);
		c=h*w-a-b;
		ans=min(ans,max({a,b,c})-min({a,b,c}));
	}
	for(long i=1;i<=h/2;i++){
		a=w*i;
		b=(h-i)/2*w;
		c=h*w-a-b;
		ans=min(ans,max({a,b,c})-min({a,b,c}));
	}
	for(long i=1;i<=w/2;i++){
		a=h*i;
		b=h/2*(w-i);
		c=h*w-a-b;
		ans=min(ans,max({a,b,c})-min({a,b,c}));
	}
	for(long i=1;i<=w/2;i++){
		a=h*i;
		b=(w-i)/2*h;
		c=h*w-a-b;
		ans=min(ans,max({a,b,c})-min({a,b,c}));
	}
	cout<<ans<<endl;
	return 