#include<iostream>
using namespace std;
int main(){
	int n,i,j;
	int a[1000];
	while(1){
		cin>>n;
		int c=0;
		int s=0;
		if(n==0)break;
		for(i=0;i<n;i++){
			cin>>a[i];
			if(a[i]<=1){
				c++;
				if(a[i]==0){
					s++;
				}
			}
		}
		if(n==1&&a[0]>=2){
			cout<<2<<endl;
		}
		else{
			if(c==n||n==1&&a[0]<=1||){
				cout<<"NA"<<endl;
			}
			else{
				cout<<n-s+1<<endl;
			}
		}
	}
	return 0;
}