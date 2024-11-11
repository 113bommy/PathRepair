#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,num,verysum=1;
	cin>>n>>num;
	if(n>=40)
	{
		cout<<1;
		return 0;
	}
	if(n==1){
		cout<<num;
		return 0;
	}
	for(int i=2;pow(i,n)<=num;i++)
	{
		while(num%long long(pow(i,n))==0)
			verysum*=i,
			num/=(pow(i,n));
	}
	cout<<verysum;
}