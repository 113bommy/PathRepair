#include<bits/stdc++.h>
using namespace std;
int main() {
	long long k,n,m;
	cin>>n>>m>>k;
	vector<long long> v1(n+2,0);
	vector<long long> v2(m+2,0);
	for(int i=1;i<=n;i++){
	    cin>>v1[i];
	    v1[i]+=v1[i-1];
	}
	for(int i=1;i<=m;i++){
	    cin>>v2[i];
	    v2[i]+=v2[i-1];
	}
	int j=m,val=0;
	for(int i=0;i<=n;i++){
	    if(v1[i]>k) break;
	    while(v2[j]>(k-v1[i]))  j--;
	    answer=max(val,(i+j));
	}
	cout<<val<<endl;
	return 0;
}