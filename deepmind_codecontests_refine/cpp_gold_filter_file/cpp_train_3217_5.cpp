
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int n=5,s=2,e=3,w=4,t=1,b=6;
	int y,z;
	int p=1;
	char sn[10];
	while(1){
		cin>>y;
		if(y==0){
			break;
		}

		for(int i=0;i<y;i++){
			cin>>sn;
			if(sn[0]=='N'){
				z=t;
				t=s;
				s=b;
				b=n;
				n=z;
				p=p+t;
			}
		else if(sn[0]=='S'){
			z=t;
			t=n;
			n=b;
			b=s;
			s=z;
			p=p+t;
		}
		else if(sn[0]=='E'){
			z=t;
			t=w;
			w=b;
			b=e;
			e=z;
			p=p+t;
		}
		else if(sn[0]=='W'){
			z=t;
			t=e;
			e=b;
			b=w;
			w=z;
			p=p+t;
		}
			else if(sn[0]=='R'){
				z=s;
				s=e;
				e=n;
				n=w;
				w=z;
				p=p+t;
			}
			else if(sn[0]=='L'){
				z=s;
				s=w;
				w=n;
				n=e;
				e=z;
				p=p+t;
			}

		}
		cout<<p<<endl;
		n=5,s=2,e=3,w=4,t=1,b=6;
		p=1;
	}

	return 0;
}