//成長し続けることが目的
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#define N_MAX 100000
#define L_MAX 50000
using namespace std;
typedef int TL;
typedef int num;
typedef pair<TL,num> I;

int N,L;
int Ice[N_MAX+2+1];
int ct = 0;
priority_queue<I> que;

void solve(){
	for(int i = 1;i <= N;i++){
		if(Ice[i] > Ice[i-1] && Ice[i] > Ice[i+1])
			que.push(make_pair(-1*(L-Ice[i]),i));
	}
	while(!que.empty()){
		I ic = que.top();que.pop();
		ct = -1 * ic.first;
		int n = ic.second;
		Ice[n] = 0;
		if(n + 1 <= N && Ice[n+1] > Ice[n+2])
			que.push(make_pair(-1*(L-Ice[n+1]+time),n+1));
		if(n - 1 >= 1 && Ice[n-1] > Ice[n-2])
			que.push(make_pair(-1*(L-Ice[n-1]+time),n-1));
	}
	printf("%d\n",ct);
	return;
}


int main() {
	scanf("%d %d",&N,&L);
	Ice[0] = 0;Ice[N+1] = 0;
	for(int n = 1;n <= N;n++)scanf("%d",&Ice[n]);
	solve();
    
    return 0;
}