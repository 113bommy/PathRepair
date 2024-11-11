#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	while(1){
		int ans=0,p=0,n,k,x,a[100001]={},flag=0,sflag=0;
		vector<int> V;
		cin>>n>>k;
		if(n==0 && k==0)
			break;
		for(int i=0;i<k;i++){
			cin>>x;
			if(x==0)
			flag=1;
			a[x]=1;
		}
		for(int i=1;i<=n;i++){
			if(sflag==0 && a[i])
				sflag=1;
			if(sflag){
				if(a[i])
					p++;
				else{
					sflag=0;
					V.push_back(p);
					p=0;
				}
			}
		}
		V.push_back(p);
		if(flag){
			for(int i=0;i<V.size()-1;i++)
				ans=max(V[i]+V[i+1]+1,ans);
		}else{
			for(int i=0;i<V.size();i++)
				ans=max(V[i],ans);
		}
		endl<<ans<<endl;
	}
	return 0;
}