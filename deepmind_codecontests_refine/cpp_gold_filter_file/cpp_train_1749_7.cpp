#include<iostream>
using namespace std;
int ans;
int main(){
	char c1,c2;
	int a,b,c=0,sum=0,f=0;
	cin>>a>>b;
	cin>>c2;
	for(int i=0;i<a-1;i++){
		c1=c2;
		cin>>c2;
		if(c1==c2)
			sum++;
		else
			f++;
	}
	if(f>2*b)
		cout<<sum+2*b;
	else
		cout<<sum+f;
  return 0;
} 