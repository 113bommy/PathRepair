#include<iostream>
#include<string>
typedef unsigned int u;
using namespace std;
typedef string::iterator s;
u z=100000000;
void p(u*a,u*l,u n){
	if(a-l)
	p(a+1,l,(n+=*a*10)/z),
	*a=n%z;	
}
u t(u*a,u*l){
	u r=0;
	char b[11]={};
	if(a-l)
	if(!t(a+1,l)){
		if(*a)cout<<*a,r=1;
	}else
		sprintf(b,"%d",*a+z),
		cout<<b+1,
		r=1;
	return r;
}
void d(u*a,u*l,u*b,u n=0){
	if(a-l)
	d(a+1,l,b+1,(n+=(*a+*b))/z),
	*a=n%z;
}
int main(){
	u n;
	cin>>n;
	string a,b;
	getline(cin,a);
	for(;n--;){
		getline(cin,a);
		getline(cin,b);
		u x[11]={},y[11]={},c=0;
		for(s i=a.begin();i!=a.end();p(x,x+10,*i++-48))
			if(++c>80)goto g;
		c=0;
		for(s i=b.begin();i!=b.end();p(y,y+10,*i++-48))
			if(++c>80)goto g;
		d(x,x+11,y);
		if(x[10])goto g;
		else if(!t(x,x+10))cout<<'0';
		if(0)
g:
		cout<<"overflow";
		cout<<'\n';
	}
}