#include<iostream>
using namespace std;
int main(){
	int n;
	double a[1024];
	int r[6]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<165)r[0]++;
		else if(a[i]<170)r[1]++;
		else if(a[i]<175)r[2]++;
		else if(a[i]<180)r[3]++;
		else if(a[i]<185)r[4]++;
		else r[5]++;
		}
	
	for(int i=0;i<6;i++){
		cout<<i+1<<':';
		for(int j=0;j<r[i];j++)cout<<'*';
		cout<<endl;
		}
		}