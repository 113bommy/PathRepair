#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,l,sum=0,mx=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l;
		sum+=l;
		mx=max(mx,l);
	}
	if((sum-mx)>mx){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

