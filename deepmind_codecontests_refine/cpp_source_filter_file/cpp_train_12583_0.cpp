#define REP(i,n) for (int i=0;i<(n);i++)???

#include <iostream>
using namespace std;
const int MAX = 8;


int set,n;
int sx,sy;
char field[MAX][MAX];

int dx[12] = {1, 0, -1, 0, 2, 0, -2, 0, 3, 0, -3, 0};???
int dy[12] = {0, 1, 0, -1, 0, 2, 0, -2, 0, 3, 0, -3};


void dfs (int x,int y){
	field[x][y] = '0';
	REP(i,12){
		int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < MAX && 0 <= ny && ny < MAX && field[nx][ny] == '1') 
				dfs(nx,ny);
		}
	return ;
}


void solve(){
	dfs(sy,sx);
	REP(i,MAX){
		REP(j,MAX){
				cout << field[i][j];
		}
		cout << endl;
	}
}

int main(){
	cin >> n;
	REP(set,n){
		REP(i,MAX){
			REP(j,MAX){
				cin >> field[i][j];
				}
			}
		cin >> sx >> sy;
		sx --; sy --;
		cout << "Data " << set+1 << ":" << endl;
		solve();
	}
}