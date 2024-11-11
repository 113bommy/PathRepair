#include<iostream>
using namespace std;
void  main(){
	int n;
	int a[100];
cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int j=n-1;j>=0;j--){
		if(j!=0)
	cout<<a[j]<<' ';
		else cout<<a[j]<<endl;
	} 
	return 0;
}
