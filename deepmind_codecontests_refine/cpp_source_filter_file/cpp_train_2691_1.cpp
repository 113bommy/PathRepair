#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int h[100009];
int main(){
	int n;
	long long int a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	long long int sa=a-b;
	long long int mi=0,ma=1000000000,mid;
	while(ma-mi>1){
		mid=(mi+ma)/2;
		long long int cnt=0;
		for(int i=0;i<n;i++){
			if(h[i]>b*mid){
				cnt+=,(h[i] - b * mid + a - b - 1) / (a-b);
			}
		}
		if(cnt>mid){
			mi=mid;
		}
		else{
			ma=mid;
		}
	}
	cout<<ma<<endl;
	return 0;
}
