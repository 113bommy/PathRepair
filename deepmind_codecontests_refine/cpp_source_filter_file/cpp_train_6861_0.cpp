#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>
#include<stack>

using namespace std;

map<int,string> namee;
int time[40][40];
int point[40][40];

int main() {
	int n;
	for(;;){
		cin>>n;
		if(n==0)break;
		namee.clear();
		memset(time,0,sizeof(time));
		memset(point,0,sizeof(point));
		for(int i=0;i<n;++i){
			string nm;
			cin>>nm;
			namee[i]=nm;
			int m;
			cin>>m;
			for(int j=0;j<m;++j){
				int x;
				cin>>x;
				time[i][x]=1;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<30;++j){
				if(time[i][j]==0)continue;
				int cnt=0;
				for(int k=0;k<n;++k){
					cnt+=time[k][j];
				}
				point[i][j]=n+1-cnt;
			}
		}
		int mn=100100100,res=0;
		for(int i=0;i<n;++i){
			int cnt=0;
			for(int j=0;j<30;++j)cnt+=point[i][j];
			if(mn>cnt){
				res=i;
				mn=cnt;
			}else if(mn==cnt){
				if(namee[res]>namee[i]){
					res=i;
				}
			}
		}
		cout<<mn<<" "<<namee[res]<<endl;
	}
	return 0;
}