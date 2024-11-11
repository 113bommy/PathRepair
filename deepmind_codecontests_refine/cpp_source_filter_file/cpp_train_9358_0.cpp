#include <iostream>
using namespace std;

int main() {
	while(1){
		int n,a,sum=0;
		cin>>n;
		if(n==0)
			break;
		for(int i=1; i<=9; i++){
			cin>>a;
			sum+=a;
			cout<<n-sum<<endl;
		}

	return 0;
}