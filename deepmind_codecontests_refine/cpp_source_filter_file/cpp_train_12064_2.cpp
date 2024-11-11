#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&n!=0){
		long long sum=0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			sum+=a;
		}
		sum/=n;
		cout<<sum<<endl;
	}
}