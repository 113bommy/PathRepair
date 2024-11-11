#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	while(1){
		int x,y,s;
		cin>>x>y>>s;

		if(x==0&&y==0&&s==0)
			break;

		int tmax=-1;

		for(int a=1;a<s-1;a++){
			int ax=a*(100+x)/100;
			int ay=a*(100+y)/100;

			for(int b=0;b<s-1;b++){
				int bx=b*(100+x)/100;
				int by=b*(100+y)/100;

				if(ax+ay==s){
					tmax=max(tmax,ax+ay);
				}
				else if(ax+ay>s){
					break;
				}
			}
		}
	
		cout<<tmax<<endl;
	}
	
	return 0;
}
