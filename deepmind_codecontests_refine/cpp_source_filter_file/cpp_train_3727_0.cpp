#include<iostream>
#include<queue>
#define int long long
using namespace std;
priority_queue<pair<int,int> > lis;
const int N=2e5+2;
int ar[N],ar1[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,z,val,mod,num=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}	
	for(i=1;i<=n;i++){
		cin>>ar1[i];
		if(ar1[i]<ar[i]){
			cout<<-1;
			return 0;
		}
		if(ar1[i]!=ar[i]){
			lis.push({ar1[i],i});
		}
	}
	while(lis.size()){
		j=lis.top().first;
		k=lis.top().second;
		lis.pop();
		if(k==1){
			l=n;
		}
		else{
			l=k-1;
		}
		z=k%n+1;
		mod=ar1[z]+ar1[l];
		val=max(ar[k],j%mod);
		i=(j-val)/mod;
		if(i==0){
			cout<<-1;
			return 0;
		}
		j-=i*mod;
		num+=i;
		ar1[k]=j;
		if(j!=ar[k]){
			lis.push({j,k});
		}
	}
	cout<<num;
}