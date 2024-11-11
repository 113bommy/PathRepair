#include "bits/stdc++.h"

using namespace std;

int N,M,K,L,R,H,W;

const long long int MOD=1000000007;



int main(){
	
	long double radius;
	vector<long double>ans;
	cout<<setprecision(20);
	while(cin>>radius>>N,r>0.5){
		vector<int>l(100);
		vector<int>r(100);
		for(int i=0;i<N;i++){
			cin>>L>>R>>K;
			r[L+50]=max(r[L+50],K);
			l[R+50]=max(l[R+50],K);
			for(int j=L+51;j<R+50;j++){
				r[j]=max(r[j],K);
				l[j]=max(l[j],K);
			}
		}
		long double ret=100;
		for(int i=-radius+1;i<radius;i++){
			long double h=min(r[i+50],l[i+50]);
			long double amari=radius*radius;
			amari-=i*i;
			amari=sqrt(amari);
			amari-=radius;
			ret=min(ret,h-amari);
		}
		ans.push_back(ret);
	}
	for(auto i:ans)cout<<i<<endl;
	return 0;
}
