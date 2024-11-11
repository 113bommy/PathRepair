#include <iostream>
using namespace std;

int HammingNumber(int n){
	int p=n;
	while(p%2 == 0)p/=2;
	while(p%3 == 0)p/=3;
	while(p%5 == 0)p/=5;
	return p==1;
}

int main() {
	
	int m,n;
	int count;
	
	while(count=0,cin>>m>>n,m){
		for(int i=m;i<=n;++i)if(HammingNumber(i))++count;
		cout << count << endl;
	}
	return 0;	
}