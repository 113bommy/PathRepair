#include<iostream>
using namespace std;
int main(){
	int n,b=1,count=0,d;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(a[b-1]!=0 && a[b-1]!=2){
		d=b;
		b=a[b-1];
		a[d-1]=0;
		count=count+1;
	}
	if(a[b-1]==2){
		cout<<count+1<<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}
