#include<bits/stdc++.h>
using namespace std;
bitset<4000005>mask(1);
int main(){
	int n,sum=0;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		mask|=mask<<x,sum+=x;
	}
	for(int i=sum+1>>1;;i++){
		if(mask.test(i))
			cout<<i,break;
	}
}
