#include <iostream>
using namespace std;

int main() {
	int n,i,j,min=1000000,max=-1000000
	long sum=0;
	
	for(cin>>n,j=0;j<n;++j){
		cin>>i;
		
		if(i<min)min=i;
		if(i>max)max=i;
		sum+=i;
	}
	
	cout<<min<<" "<<max<<" "<<sum<<endl;
	
	return 0;
}