#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <cstring>
#include <sstream>
#define MOD 1000000007LL

using namespace std;

typedef long long ll;
typedef string::const_iterator State;
typedef pair<int,int> P;
int n[4];
int all;
int m;
string str[51];
map<string,int> ind;
vector<P> vec[51];
vector<int> rule;
ll dp[51][51][51][51];

void make_rule(int v){
	if(all<rule.size())return;
	for(int i=0;i<vec[v].size();i++){
		if(vec[v][i].first==0){
			rule.push_back(vec[v][i].second);
		}else{
			make_rule(vec[v][i].second);
		}
	}
}

void parse_2(State &begin,State &end,int par){
	if(*begin==' ')begin++;
	if(begin==end)return;
	if(*begin=='['){
		begin++;
		int bit=0;
		while(*begin!=']'){
			if(*begin=='A')bit|=(1<<0);
			if(*begin=='T')bit|=(1<<1);
			if(*begin=='G')bit|=(1<<2);
			if(*begin=='C')bit|=(1<<3);
			begin++;
		}
		begin++;
		vec[par].push_back(P(0,bit));
	}else{
		string st="";
		while(*begin!=' ' && begin!=end){
			st+=*begin;
			begin++;
		}
		if(ind.find(st)==ind.end()){
			int next=ind.size();
			ind[st]=next;
		}
		vec[par].push_back(P(1,ind[st]));
	}
	parse_2(begin,end,par);
	return;
}

void parse_1(State &begin,State &end){
	string st="";
	while(*begin!=':'){
		st+=*begin;
		begin++;
	}
	if(ind.find(st)==ind.end()){
		int next=ind.size();
		ind[st]=next;
	}
	int par=ind[st];
	begin++;
	begin++;
	parse_2(begin,end,par);
	return;
}

int main(void){
	for(int i=0;i<4;i++){
		scanf("%d",&n[i]);
		all+=n[i];
	}
	scanf("%d%*c",&m);

	for(int i=0;i<m;i++){
		getline(cin,str[i]);
		State begin=str[i].begin();
		State end=str[i].end();
		parse_1(begin,end);
	}
	make_rule(0);
	dp[0][0][0][0]=1;
	for(int i=0;i<rule.size();i++){
		int g[4];
		for(g[0]=0;g[0]<=n[0];g[0]++){
			if(g[0]>i)continue;
			for(g[1]=0;g[1]<=n[1];g[1]++){
				if(g[0]+g[1]>i)continue;
				for(g[2]=0;g[2]<=n[2];g[2]++){
					if(g[0]+g[1]+g[2]>i)continue;
					if(dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]]>=1){
						if((rule[i]>>0 & 1) && g[0]+1<=n[0]){
							dp[g[0]+1][g[1]][g[2]][i-g[0]-g[1]-g[2]]+=dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]];
							if(dp[g[0]+1][g[1]][g[2]][i-g[0]-g[1]-g[2]]>=MOD)dp[g[0]+1][g[1]][g[2]][i-g[0]-g[1]-g[2]]-=MOD;
						}
						if((rule[i]>>1 & 1) && g[1]+1<=n[1]){
							dp[g[0]][g[1]+1][g[2]][i-g[0]-g[1]-g[2]]+=dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]];
							if(dp[g[0]][g[1]+1][g[2]][i-g[0]-g[1]-g[2]]>=MOD)dp[g[0]][g[1]+1][g[2]][i-g[0]-g[1]-g[2]]-=MOD;
						}
						if((rule[i]>>2 & 1) && g[2]+1<=n[2]){
							dp[g[0]][g[1]][g[2]+1][i-g[0]-g[1]-g[2]]+=dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]];
							if(dp[g[0]][g[1]][g[2]+1][i-g[0]-g[1]-g[2]]>=MOD)dp[g[0]][g[1]][g[2]+1][i-g[0]-g[1]-g[2]]-=MOD;
						}
						if((rule[i]>>3 & 1) && i-g[0]-g[1]-g[2]+1<=n[3]){
							dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]+1]+=dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]];
							if(dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]+1]>=MOD)dp[g[0]][g[1]][g[2]][i-g[0]-g[1]-g[2]+1]-=MOD;
						}
					}
				}
			}
		}
	}
	printf("%lld\n",all==rule.size()?dp[n[0]][n[1]][n[2]][n[3]]:0);
	return 0;
}