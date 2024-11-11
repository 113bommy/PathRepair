#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,l,sum=0,max=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l;
		sum+=l;
		max=max(max,l);
	}
	if((sum-max)>max){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

