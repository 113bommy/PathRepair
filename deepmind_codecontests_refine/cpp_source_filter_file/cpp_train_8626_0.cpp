#include<iostream>
using namespace std;

int main(){

	bool is_prime[50000];
	
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<50000;i++){
		is_prime[i]=true;
	}
	
	for(int i=2;i*i<50000;i++){
		if(is_prime[i]){
			for(int j=i*i;j<50000;j+=i){
				is_prime[j]=false;
			}
		}
	}
	
	
	while(true){
		int n;
		cin>>n;
		int count=0;
		
		if(n==0)
			break;
		
		for(int i=2;i<=(n/2);i++){
			if(is_prime[i]&&is_prime[n-i]){
				if(
					count++;
			}
		}
		
		cout<<count<<endl;
		}
	
	
	return 0;
	
}