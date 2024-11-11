#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,l[2000],a=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>l[i];
	sort(l,l+n);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			long long k=j,r=N;
			while(r-k>1){
				long long m=(k+r)/2;
				if(l[m]<l[i]+l[j])
					k=m;
				else
					r=m;
			}
			a+=k-j;
		}
	cout<<a<<endl;
}