#include <iostream>
#include <cstring>

using namespace std;

char dx[] = {-1,1,0,0};
char dy[] = {0,0,-1,1};
char dice[6][2] = {
	{4,2}, {3,5}, {5,0}, {1,4}, {0,3}, {2,1}
};

int board[9], goal[9];

void dfs(int x, int y, int px, int py, int step, int &res){
	if(step >= res) return;
	int space = 3*x+y;
	for(int i=0;i<4;i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx<0||3<=nx||ny<0||3<=ny) continue;
		if(nx==px&&ny==py) continue;
		int mv = 3*nx+ny;
		int tmp = board[mv];
		board[space] = dice[board[mv]][i/2];
		board[mv] = 6;
		int dif = 0;
		for(int j=0;j<9;j++) dif += (goal[j]!=board[j]/2);
		if(dif==0) res = step;
		if(step+dif-1<ans) dfs(nx, ny, x, y, step+1, ans);
		board[space] = 6;
		board[mv] = tmp;
	}
}

int main(){
	int x, y;
	while(cin >> y >> x, y){
		char c;
		for(int i=0;i<9;i++) {
			cin >> c;
			if(c=='W') goal[i] = 0;
			if(c=='B') goal[i] = 1;
			if(c=='R') goal[i] = 2;
			if(c=='E') goal[i] = 3;
		}
		memset(board,0,sizeof(board));
		board[3*(x-1)+y-1] = 6;
		int dif = 0;
		for(int i=0;i<9;i++) dif += (goal[i]!=board[i]/2);
		int res = dif ? 31 : 0;
		dfs(x-1,y-1,-1,-1,1,res);
		cout << (res==31?-1:res) << endl;
	}
}