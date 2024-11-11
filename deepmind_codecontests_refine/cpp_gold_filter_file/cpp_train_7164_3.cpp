#include <bits/stdc++.h>
using namespace std;
int dis[20000 + 3][20000 + 3];
int main(){
	int n,m,q,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d%d",&x,&y);
		dis[x][y]++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			dis[i][j] += dis[i][j - 1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i - 1;j >= 1;j--){
			dis[j][i] += dis[j + 1][i];
		}
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]);
	}
	return 0;
}