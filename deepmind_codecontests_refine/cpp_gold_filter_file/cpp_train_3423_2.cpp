#include<iostream>
using namespace std;

int main(){
	
	double a[2];
	int b[4][2]={0};
	while(cin>>a[0]>>a[1]){
	for(int i=0;i<2;i++){
	if(a[i]<0.2)
		b[3][i]++;
	else if(a[i]<0.6)
		b[2][i]++;
	else if(a[i]<1.1)
		b[1][i]++;
	else
		b[0][i]++;
	}
	}
	for(int i=0;i<4;i++)
		cout<<b[i][0]<<" "<<b[i][1]<<endl;
	

}