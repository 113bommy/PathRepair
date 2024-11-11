#include <iostream>
using namespace std;

int main() {
	int a,b;
	int i,j;
	for(;;){
	cin>>a>>b;
	
	if(a==0&&b==0){
		break;
	}
	
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			
			cout<<'#';
			
		}
		cout<<endl;
	}
	cout<<endl;
	}
	retrun 0;
}