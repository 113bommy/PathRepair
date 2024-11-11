#include<bits/stdc++.h>
using namespace std;
const int MN=260000;
int x[520][520];
int cnt[MN][4];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>x[i][j];
		}
	}
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(x[i][j]%2==1){
				x[i][j]--;
				x[i][j+1]++;
				cnt[res][0]=i;
				cnt[res][1]=j;
				cnt[res][2]=i;
				cnt[res][3]=j+1;
				res++;
			}
		}
	}
	int ax=m-1;
	for(int i=0;i<n-1;i++){
		if(x[i][ax]%2==1){
			x[i][ax]--;
			x[i+1][ax]++;
			cnt[res][0]=i;
			cnt[res][1]=ax;
			cnt[res][2]=i+1;
			cnt[res][3]=ax;
			res++;
		}
	}
	cout<<res<<endl;
	for(int i=0;i<res;i++){
		cout<<cnt[i][0]+1<<" "<<cnt[i][1]+1<<" "<<cnt[i][2]+1<<" "<<cnt[i][3]+1<<endl;
	}
	return 0;
}