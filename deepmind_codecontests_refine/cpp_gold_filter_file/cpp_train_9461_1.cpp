#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int n,P,Q,R,C,flag;
struct DATA{
int name,p,f,c,cal,sum,flag;
};
DATA data[1001];

int main(){
	while(1){
		flag=0;
		for(int i=0;i<n;i++){data[i].flag=0;}
		cin>>n;
		if(n==0){break;}
		for(int i=0;i<n;i++){
			cin>>data[i].name>>data[i].p>>data[i].f>>data[i].c;
			data[i].cal=data[i].p*4+data[i].f*9+data[i].c*4;
		}
		cin>>P>>Q>>R>>C;
		for(int i=0;i<n;i++){
			if(data[i].p<=P && data[i].f<=Q && data[i].c<=R && data[i].cal<=C){
				data[i].flag=1;
			}
		}
		for(int i=0;i<n;i++){
			if(data[i].flag==1){
				cout<<data[i].name<<endl;
				flag++;
			}
		}
		if(flag==0){cout<<"NA"<<endl;}
	}
	return 0;
}