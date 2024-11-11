#include <iostream>
using namespace std;

int main() {
	int n;
	long long lucas[100]={2,1};
	cin>>n;
	
	for(int i=2,i<100;i++)lucas[i]=lucas[i-1]+lucas[i-2];
	cout<<lucas[n]<<endl;
}
