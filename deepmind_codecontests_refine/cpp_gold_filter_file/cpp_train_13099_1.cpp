#include<iostream>
#include<bitset>
using namespace std;
int n,x,sum;
bitset<2000007>f;
int main(){
	cin>>n;
	f[0]=1;
	for(int i=0;i<n;i++){
		cin>>x;
		f|=f<<x;
		sum+=x;
	}
	for(int i=(sum+1)/2;i<=sum;i++){
		if(f[i]) {cout<<i<<endl;break;}
	}
	return 0;
}