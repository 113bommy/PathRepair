#include<bits/ctdc++.h>
using namespace std;
int main(){
	char a[3];
	int b=700;
	for(int i=0;i<3;i++){
		cin>>a[i];
		if(a[i]=='o') b+=100;
	}
	cout<<b<<endl;
	return 0;
}
