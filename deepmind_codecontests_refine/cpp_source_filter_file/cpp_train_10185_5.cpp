#include <iostream>
using namespace std;
int main(){
	int a,b,c,d,count=0;
	cin>>a>>b>>c>>d;
	int i,j,k;
	for(i=0; i<=a; i++){
		for(j=0; j<=b; j++){
			for(K=0; k<=c; k++){
				if(500*i+100*j+50*k==d) count++;
			}
		}
	}
	cout<<count;
}