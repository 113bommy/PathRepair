#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100000


struct Info{
	Info(int arg_id,int arg_value){
		id = arg_id;
		value = arg_value;
	}
	bool operator<(const struct Info &arg) const{
		return value < arg.value;
	}
	int id,value;
};

struct Data{
	Data(int arg_node_id,int arg_value){
		node_id = arg_node_id;
		value = arg_value;
	}
	bool operator<(const struct Data &arg){
		return value > arg.value;
	}

	int node_id,value;
};

int N;
int contribution[NUM];
int boss[NUM],height[NUM],member_num[NUM];
int salary[NUM],in_num[NUM];
vector<Info> V[NUM];
vector<int> G[NUM];

int group_index;

int get_boss(int id){
	if(boss[id] == id)return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

int is_same(int x,int y){
	return get_boss(x) == get_boss(y);
}

void unite(int x,int y){
	int boss_x = get_boss(x);
	int boss_y = get_boss(y);

	if(boss_x == boss_y)return;

	if(height[x] > height[y]){

		boss[boss_y] = boss_x;

	}else if(height[x] < height[y]){

		boss[boss_x] = boss_y;

	}else{ //height[x] == height[y]

		boss[boss_y] = boss_x;
		height[x]++;
	}
}

int main(){

	scanf("%d",&N);
	for(int i = 0; i < N; i++)scanf("%d",&contribution[i]);

	for(int i = 0; i < N; i++){
		boss[i] = i;
		height[i] = 0;
		member_num[i] = 1;
	}

	int M;
	scanf("%d",&M);

	int a,b;
	for(int loop = 0; loop < M; loop++){
		scanf("%d %d",&a,&b);
		a--;
		b--;
		V[a].push_back(Info(b,contribution[b]));
		V[b].push_back(Info(a,contribution[a]));

		if(contribution[a] < contribution[b]){
			G[a].push_back(b);
		}else if(contribution[a] > contribution[b]){
			G[b].push_back(a);
		}else{ //contribution[a] == contribution[b]
			unite(a,b);
		}
	}

	for(int i = 0; i < N; i++){

		if(V[i].size() <= 1)continue;

		sort(V[i].begin(),V[i].end());
		for(int k = 1; k < V[i].size(); k++){
			if(V[i][k].value == V[i][k-1].value){
				unite(V[i][k].id,V[i][k-1].id);
			}else{ //V[i][k].value > V[i][k-1].value
				G[V[i][k-1].id].push_back(V[i][k].id);
			}
		}
	}

	int boss_id,to_boss_id;
	for(int i = 0; i < N; i++){
		boss_id = get_boss(i);
		if(boss_id == i){

			for(int k = 0; k < G[boss_id].size(); k++){
				to_boss_id = get_boss(G[boss_id][k]);
				G[boss_id][k] = to_boss_id;
			}

		}else{
			member_num[boss_id]++;

			for(int k = 0; k < G[i].size(); k++){
				G[boss_id].push_back(to_boss_id = get_boss(G[i][k]));
			}
		}
	}

	for(int i = 0; i < NUM; i++)in_num[i] = 0;

	for(int i = 0; i < N; i++){
		if(boss[i] != i)continue;

		sort(G[i].begin(),G[i].end());
		G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());

		for(int k = 0; k < G[i].size(); k++){
			in_num[G[i][k]]++;
		}
	}

	for(int i = 0; i < NUM; i++){
		salary[i] = 1;
	}

	priority_queue<Data> Q;

	for(int i = 0; i < NUM; i++){
		if(boss[i] != i)continue;

		Q.push(Data(i,contribution[i]));
	}

	while(!Q.empty()){

		for(int i = 0; i < G[Q.top().node_id].size(); i++){
			salary[G[Q.top().node_id][i]] = max(salary[G[Q.top().node_id][i]],salary[Q.top().node_id]+1);
		}
		Q.pop();
	}

	ll ans = 0;

	for(int i = 0; i < NUM; i++){
		if(boss[i] == i){
			ans += salary[i]*member_num[i];
		}
	}

	printf("%lld\n",ans);

	return 0;
}


