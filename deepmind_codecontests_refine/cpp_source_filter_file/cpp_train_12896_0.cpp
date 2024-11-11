#include<iostream>
#include<cstdlib>
#include<cstdio>
#define w 15*16+15
using namespace std;
int fld[8][3]={0,0,0,0,0,w,0,w,
	0,0,w,w,w,0,0
	,w,0,w,w,w,0,w,w,w};
char* col[]={"black",
	"blue","lime","aqua",
	"red","fuchsia",
	"yellow","white"};
int main(){
	int temp,t,x,y,z,a[8],ren;
	char s[10];
	while(cin>>s,s[0]!='0'){
		temp=1000000;
		for(int i=1;i<8;i++){
			if(s[i]>'9')
			a[i-1]=9+s[i]-'a';
			else a[i-1]=s[i]-'0';
		}
		for(int i=0;i<8;i++){
			x=a[0]*16+a[1]-fld[i][0];
			y=a[2]*16+a[3]-fld[i][1];
			z=a[4]*16+a[5]-fld[i][2];
			ren=sqrt(x*x+y*y+z*z);
			if(ren<temp){
				t=i;
				temp=ren;
			}
		}cout<<col[t]<<endl;
	}
	return 0;
}