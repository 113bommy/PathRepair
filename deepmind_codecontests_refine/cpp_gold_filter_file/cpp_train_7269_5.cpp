#include <iostream>
using namespace std;

int main()
{
	int n,y,i,j,k;
	cin>>n>>y;
	
	for(i=0;i<=y/10000;i++){
		for(j=0;j<=y/5000;j++){
			k=n-i-j;
			if(k>=0&&i*10000+j*5000+k*1000==y){
				cout<<i<<" "<<j<<" "<<k<<endl;
				return 0;
			}
		}
	}
	cout<<"-1 -1 -1"<<endl;
	
	return 0;
}