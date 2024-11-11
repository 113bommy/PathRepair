//https://atcoder.jp/contests/arc100/tasks/arc100_b
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);
	int64_t s1=0,s2=0,s3=0,s4=0;
	for(int& x:a){
		std::cin>>x;
		s4+=x;
	}
	int i=0,k=0;
	int64_t ans=1e18;
	for(int j=0;j<n;){
		if(0<i&&i<j&&j<k&&k<n){
			ans=std::min(ans,
					std::max({s1,s2,s3,s4})-
					std::min({s1,s2,s3,s4}));
		}

		s2+=a[j];s3-=a[j];++j;
		while(i<n&&std::abs(s1+a[i]-(s2-a[i]))<std::abs(s1-s2)){
			s1+=a[i];s2-=a[i];++i;
		}
		while(k<n&&std::abs(s3+a[k]-(s4-a[k]))<std::abs(s3-s4)){
			s3+=a[k];s4-=a[k];++i;
		}
	}
	std::cout<<ans<<'\n';
}

#error