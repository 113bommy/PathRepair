#include<iostream>
int main(){
	long n,i,x;
	std::cin>>n;
	for(i=1;i*i+i<n;i++) n%i?:x+=n/i-1;
	printf("%ld\n",x);
}