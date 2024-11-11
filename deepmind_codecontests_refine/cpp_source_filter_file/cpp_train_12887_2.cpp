#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long N,ans=0;
	cin>>N;
	vector<long long> L(N);
	rep(i,N)cin>>L[i];
	sort(L,begin(),L.end());
	for(int i=0;i<N-2;++i){
		for(int j=i+1;j<N-1;++j){
			for(int k=j+1;k<N;++k){
				if (L[k]<L[i]+L[j]) ++ans;
			}
		}
	}
	cout<<ans<<"\n";
}