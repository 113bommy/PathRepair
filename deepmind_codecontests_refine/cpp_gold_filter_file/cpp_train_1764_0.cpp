#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;


int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char dc[5] = "NESW";
char Map[25][25];

int main(){
	int x,y,n,m,i,j;
	while(cin >> n, n){
		int sx, sy;
		for(i=0;i<=20;i++)
			for(j=0;j<=20;j++)
				Map[i][j] = 0;
		for(i=0;i<n;i++){
			cin >> x >> y;
			Map[x][y] = 1;
		}
		cin >> m;
		int ans = 0;
		x=10;y=10;
		for(j=0;j<m;j++){
			char c;
			int t;
			cin >> c >> t;
			int dt;
			for(i=0;i<4;i++) if(c == dc[i]) dt=i;
			for(i=0;i<t;i++){
				x += d[dt][0];
				y += d[dt][1];
				if(Map[x][y]){
					ans ++;
					Map[x][y] = 0;
				}
			}
		}
		cout << (ans == n ? "Yes":"No") << endl;
	}
	return 0;
}