#include<iostream>
using namespace std;

int main(){
	int n,a;
while(){
	scanf("%d",&n);
if(n==0)break;
	for(int i=0;i<9;i++){
		scanf("%d",&a);
		n-=a;
	}
	printf("%d\n",n);
}}