#include<iostream>
int main(){
	long long int n,i,ans=0;
	std::cin >> n;
	for(i=1;i*i<=n;i++) if(n%i==0&&i<n/i-1) ans+=n/i-1;
	std::cout << ans << std::endl;
}