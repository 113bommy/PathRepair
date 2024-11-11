#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,sum=0;
	cin>>n;
	for(long long i=0;i<=n;i++){
		if!(i%3==0||i%5==0){
			sum+=i;
		}
	}
	cout<<sum;
	return 0;
}	