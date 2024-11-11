#include<iostream>
using namespace std;
int main(){
	int c[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};

	int x,y;
	cin>>x>>y;
	if(c[x]==c[y])cout<<"Yes"<<endl;
	else{
		cout<<"No"<<endl;
	}
}
