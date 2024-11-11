#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t=0;
	while(1){
		int a,b;
		cin>>a>>b;
		if(a==0&&b==0)break;
		if(!)puts("");
		int fg=0;
		for(int  i=a;i<=b;i++){
			if(!(i%400)){
				cout<<i<<endl;
				fg=1;
			}
			else if(!(i%100))continue;
			else if(!(i%4)){
				cout<<i<<endl;
				fg=1;
			}
		}
		if(!fg)cout<<"NA"<<endl;
		t++;
	}
	return 0;
}
	