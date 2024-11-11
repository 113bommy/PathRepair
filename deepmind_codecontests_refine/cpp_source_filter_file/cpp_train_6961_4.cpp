#include<bits/c++std.h>
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<math.h>
#include<bitset>
using namespace std;
int main(){
	int a,b;
	char map[64];
	int movex[4]={1,0,-1,0},movey[4]={0,1,0,-1};
	while(cin>>map[0]){
		for(int i=1;i<64;i++){
			cin>>map[i];
		}
		int i,j;
		for(i=0;i<64;i++){
			if(map[i]=='1'){
				break;
			}
		}
		if(map[i+1]=='1'){
			if(map[i+8]=='1'&&map[i+9]=='1'){
				cout<<"A"<<endl;
			}
			else if(map[i+2]=='1'&&map[i+3]=='1'){
				cout<<"C"<<endl;
			}
			else if(map[i+9]=='1'&&map[i+10]=='1'){
				cout<<"E"<<endl;
			}
			else if(map[i+7]=='1'&&map[i+8]=='1'){
				cout<<"G"<<endl;
			}
		}
		else if(map[i+8]=='1'){
			if(map[i+16]=='1'&&map[i+24]=='1'){
				cout<<"B"<<endl;
			}
			else if(map[i+7]=='1'&&map[i+15]){
				cout<<"D"<<endl;
			}
			else if(map[i+9]=='1'&&map[i+17]=='1'){
				cout<<"F"<<endl;
			}
		}
		memset(map,'0',sizeof(map));
	}
	return 0;
}