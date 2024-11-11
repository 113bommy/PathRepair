#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int,int> P;
int n,k,S,cnt,l,r,ans;
P p[111111];
set<int>st;
multiset<int>ml;
signed main(){
	cin>>n>>k;
	rep(i,n){
		cin>>p[i].second>>p[i].first;
		st.insert(p[i].second);
	}
	sort(p,p+n,greater<P>());
	S=st.size();
	st.erase(st.begin(),st.end());
	rep(i,k){
		cnt+=t[i].first;
		ml.insert(p[i].second);
		st.insert(p[i].second);
	}
	l=k-1,r=k;
	ans=st.size()*st.size()+cnt;
	for(int i=st.size();i<min(k,S);i++){//i:種類数
		while(ml.count(p[l].second)==1)l--;
		while(1){
			if(ml.find(p[r].second)==ml.end()){
				cnt+=p[r].first-p[l].first;
				ml.erase(ml.find(p[l].second));
				l--;
				ml.insert(p[r].second);
				break;
			}
			r++;
		}
		ans=max(ans,(i+1)*(i+1)+cnt);
	}
	cout<<ans<<endl;
	return 0;
}
