#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
 
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

int n,m,l;
vector<vector<PP> > edge;


int solve()
{
	
	//??????i??§?????????j????????????????????°
	vector<vector<long> > memo(n,vector<long>(l+1,1000000));
	
	for(int i=0;i<=l;i++) memo[0][i]=0;
	
	priority_queue<PP,vector<PP>,greater<PP> > q;
	
	//?????¨??°0,??????0,?????????l
	q.push(PP(0,P(0,l)));
	
	while(!q.empty()){
		PP tmp=q.top(); q.pop();
		
		int now_v=tmp.first;
		int now_e=tmp.second.first;
		int now_l=tmp.second.second;
								
		for(int i=0;i<edge[now_v].size();i++){
			int to=edge[now_v][i].first;
			int e_num=edge[now_v][i].second.second;
			int cost=edge[now_v][i].second.first;

			//???????????????
			if(now_l>=cost){
				if(memo[to][now_l-cost]>memo[now_v][now_l]){
					memo[to][now_l-cost]=memo[now_v][now_l];
					q.push(PP(to,P(now_e,now_l-cost)));
				}
			}
			
			//?????????????????????
			if(memo[to][now_l]>memo[now_v][now_l]+e_num){
				memo[to][now_l]=memo[now_v][now_l]+e_num;
				q.push(PP(to,P(now_e+e_num,now_l)));
			}			
		}
		
	}
	
	int ans=memo[n-1][0];
	for(int i=1;i<=l;i++) ans=min(ans,memo[n-1][i]);
	
	return ans;
	
}

int main()
{
	
	while(cin>>n>>m>>l,n){		
			
		edge.clear();
		edge.resize(n);
		
		for(int i=0;i<m;i++){
			int a,b,d,e;
			cin>>a>>b>>d>>e;
			a--; b--;
			
			edge[a].push_back(PP(b,P(d,e)));
			edge[b].push_back(PP(a,P(d,e)));
			
		}
		cout<<solve()<<endl;
		
	}
		
	

	return 0;
}